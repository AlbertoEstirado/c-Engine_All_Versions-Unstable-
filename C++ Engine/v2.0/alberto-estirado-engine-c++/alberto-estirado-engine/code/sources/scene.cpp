/**
*
* @author Alberto Estirado L?pez
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/

#include <scene.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <transform.hpp>
#include <kernel.hpp>
#include <light_component.hpp>
#include <camera_component.hpp>
#include <keyboardcontrol_component.hpp>
#include <mesh_component.hpp>
#include <box_collider_component.hpp>
#include <Render_Node.hpp>
#include <rigibody2d_component.hpp>
#include <physics2d_system.hpp>
#include <joint_component.hpp>

using namespace rapidxml;
using namespace std;

namespace engine
{
	Scene::Scene(const std::string & name, const std::string & path, Window & window)
	{
		this->name = name;
		this->path = path;

		state = UNINITIALIZED;

		Scene_manager::instance().add_scene(this);

		renderer_system.reset(new Renderer_System(window));
		control_system.reset(new Control_System);
		dispatcher.reset(new Dispatcher);
		collision_system.reset(new Collision_System);
		physics2d_system.reset(new Physics2d_System(true));
	}

	void Scene::load_scene()
	{
		//Start loading the scene
		state = LOADING;

		//Load the xml file
		xml_document<> doc;
		ifstream file(path); 
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		std::string content(buffer.str());

		//Parse the document
		doc.parse<0>(&content[0]);

		//Start reading the document
		xml_node<>* pRoot = doc.first_node();
		
		for (xml_node<>* entity = pRoot->first_node()->first_node();
			entity; entity = entity->next_sibling())
		{
			//Get id entity
			xml_attribute<>* pAttr = entity->first_attribute("id");
			std::string strValue = pAttr->value();

			//Create a new entity
			Entity* newEntity = new Entity(strValue, this);
			
			parse_node_component(entity, newEntity);
			
			//Add the entity to the scene
			add_entity(newEntity);
		}

		awake();
	}

	void Scene::reset_transforms()
	{
		//Load the xml file
		xml_document<> doc;
		ifstream file(path);
		stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		std::string content(buffer.str());

		//Parse the document
		doc.parse<0>(&content[0]);

		//Start reading the document
		xml_node<>* pRoot = doc.first_node();

		for (xml_node<>* entity = pRoot->first_node()->first_node();
			entity; entity = entity->next_sibling())
		{
			//Get id entity
			xml_attribute<>* pAttr = entity->first_attribute("id");
			std::string strValue = pAttr->value();
			//std::cout << strValue << std::endl;
			Entity * e = get_entity(strValue);

			for (xml_node<>* component = entity->first_node();
				component; component = component->next_sibling())
			{
				xml_attribute<>* cAttr = component->first_attribute("id");
				std::string strCValue = cAttr->value();

				//Reset transform
				if (strCValue == "transform")
				{
					Matrix44 transform;

					//Position
					transform[0][0] = std::stof(component->first_node()->first_node()->value());
					transform[0][1] = std::stof(component->first_node()->first_node()->next_sibling()->value());
					transform[0][2] = std::stof(component->first_node()->last_node()->value());
					//Rotation
					transform[1][0] = std::stof(component->first_node()->next_sibling()->first_node()->value());
					transform[1][1] = std::stof(component->first_node()->next_sibling()->first_node()->next_sibling()->value());
					transform[1][2] = std::stof(component->first_node()->next_sibling()->last_node()->value());
					//Scale
					transform[2][0] = std::stof(component->last_node()->first_node()->value());
					transform[2][1] = std::stof(component->last_node()->first_node()->next_sibling()->value());
					transform[2][2] = std::stof(component->last_node()->last_node()->value());

					e->get_transform()->set_transform_from_Matrix(transform);
				}
			}
		}

		for (auto& component : physics2d_system->components)
		{
			auto physics_component = dynamic_cast<Rigibody2d_Component*>(component);
			physics_component->body->SetLinearVelocity({ 0,0 });
			physics_component->body->SetTransform({ component->entity->transform->position.x,component->entity->transform->position.y }, 
													component->entity->transform->rotation.z);
		}
	}

	void Scene::parse_node_component(xml_node<>* xml_entity, Entity* newEntity)
	{
		for (xml_node<>* component = xml_entity->first_node();
			component; component = component->next_sibling())
		{
			xml_attribute<>* cAttr = component->first_attribute("id");
			std::string strCValue = cAttr->value();

			//Parse the different components and we add them to the entity
			if (strCValue == "transform")
			{
				parse_transform(component, newEntity);
			}
			else if (strCValue == "mesh_component")
			{
				newEntity->add_component(new Mesh_Component(newEntity, component->value(), *renderer_system));
			}
			else if(strCValue == "camera_component")
			{
				newEntity->add_component(new Camera_Component(newEntity, *renderer_system));
			}
			else if (strCValue == "light_component")
			{
				newEntity->add_component(new Light_Component(newEntity, *renderer_system));
			}
			else if (strCValue == "keyboardcontrol_component")
			{
				newEntity->add_component(new Keyboardcontrol_Component(newEntity));
			}
			else if (strCValue == "box_collider_component")
			{
				parse_box_collider_component(component, newEntity);
			}
			else if (strCValue == "rigibody2d_component") 
			{
				parse_rigibody2d(component, newEntity);
			}
			else if (strCValue == "joint_component")
			{
				parse_joint(component, newEntity);
			}
		}
	}

	void Scene::parse_joint(xml_node<>* component, Entity* newEntity)
	{
		std::string body1 = component->first_node()->value();
		std::string body2 = component->first_node()->next_sibling()->value();

		bool enableMotor = std::stof(component->last_node()->value());

		newEntity->add_component(new Joint_Component(
			newEntity,
			*physics2d_system,
			newEntity->get_component<Rigibody2d_Component>(),
			get_entity(body1)->get_component<Rigibody2d_Component>(),
			enableMotor
		));
	}

	void Scene::parse_rigibody2d(xml_node<>* component, Entity* newEntity)
	{
		bool isStatic = std::stof(component->first_node()->value());
		bool isSensor = std::stof(component->last_node()->value());
		
		std::string type_value = component->first_node()->next_sibling()->first_attribute("type")->value();
		if(type_value == "box")
		{
			float x = std::stof(component->first_node()->next_sibling()->first_node()->first_node()->value());
			float y = std::stof(component->first_node()->next_sibling()->first_node()->first_node()->next_sibling()->value());
			//std::cout << "x: " << x << std::endl;
			//std::cout << "y: " << y << std::endl;

			newEntity->add_component(new Rigibody2d_Component(newEntity, *physics2d_system, isStatic, isSensor,{ x,y }));
		}
		else
		{
			float radius = std::stof(component->first_node()->next_sibling()->first_node()->first_node()->value());
			//std::cout << "radio: " << radius << std::endl;
			newEntity->add_component(new Rigibody2d_Component(newEntity, *physics2d_system, isStatic, isSensor, Rigibody2d_Component::Circle{radius}));
		}
	}

	void Scene::parse_transform(xml_node<>* component, Entity* newEntity)
	{
		Entity* parent = nullptr;
		if (component->last_attribute("parent"))
		{
			parent = get_entity(component->last_attribute("parent")->value());
		}

		Matrix44 transform;

		//Position
		transform[0][0] = std::stof(component->first_node()->first_node()->value());
		transform[0][1] = std::stof(component->first_node()->first_node()->next_sibling()->value());
		transform[0][2] = std::stof(component->first_node()->last_node()->value());
		//Rotation
		transform[1][0] = std::stof(component->first_node()->next_sibling()->first_node()->value());
		transform[1][1] = std::stof(component->first_node()->next_sibling()->first_node()->next_sibling()->value());
		transform[1][2] = std::stof(component->first_node()->next_sibling()->last_node()->value());
		//Scale
		transform[2][0] = std::stof(component->last_node()->first_node()->value());
		transform[2][1] = std::stof(component->last_node()->first_node()->next_sibling()->value());
		transform[2][2] = std::stof(component->last_node()->last_node()->value());

		if (parent)
			newEntity->add_transform(new Transform(newEntity, transform, parent->get_transform()));
		else
			newEntity->add_transform(new Transform(newEntity, transform));
	}

	void Scene::parse_box_collider_component(xml_node<>* component, Entity* newEntity)
	{
		//Get scale in the xml
		float scale_x = std::stof(component->first_node()->value());
		float scale_z = std::stof(component->first_node()->next_sibling()->value());

		//Get the type of the collider
		std::string s_type = component->last_node()->value();

		engine::Collider_Component::Type type;

		//Base on the type, it will be added in differnet lists
		if(s_type == "dynamic")
		{
			type = engine::Collider_Component::Type::DYNAMIC;
		}
		else
		{
			type = engine::Collider_Component::Type::STATIC;
		}

		Box_Collider_Component* box_collider = new Box_Collider_Component(newEntity, scale_x, scale_z, type);
		newEntity->add_component(box_collider);
		collision_system->add_collider(box_collider);
	}

	void Scene::add_entity(Entity * new_entity)
	{
		entities.insert(std::pair<Id, Entity*>(new_entity->id, new_entity));
	}

	Entity* Scene::get_entity(const std::string & id)
	{
		for (auto& e : entities)
		{
			if(e.first == id)
			{
				return e.second;
			}
		}
		return nullptr;
	}

	void Scene::awake()
	{
		state = ONGOIN;
		start();
	}

	void Scene::start()
	{
	}

	void Scene::update(float time)
	{
		//We run all the systems that need to be running
		control_system->run(time);
		collision_system->run(time);
		physics2d_system->run(time);
	}

	void Scene::render()
	{
		//Run the render system
		renderer_system->run(0);
	}


	Dispatcher& Scene::get_dispatcher()
	{
		return *dispatcher;
	}
}
