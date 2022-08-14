
#include <LevelEditor/serializer.hpp>

namespace level_editor
{

	API const char* Serializer::save_string(const std::string& string)
	{
		strings.emplace_back(string);
		return strings.back().c_str();
	}

	API void Serializer::save_scene(level_editor::Scene scene)
	{
		
		xml_node<>* decl = doc.allocate_node(node_declaration);
		decl->append_attribute(doc.allocate_attribute("version", "1.0"));
		doc.append_node(decl);
		xml_node<>* root = doc.allocate_node(node_element, "scene");
		root->append_attribute(doc.allocate_attribute("id", scene.name.c_str()));
		xml_node<>* entities = doc.allocate_node(node_element, "entities");
		doc.append_node(root);
		//doc.append_node(entities);
		for (size_t i = 0; i < scene.entities.size(); i++)
		{
			nodes.emplace_back(save_entity(entities, scene.entities[i]));
			entities->append_node(nodes.back());
		}
		root->append_node(entities);
		std::ofstream file(scene.name + ".xml");
		//file << doc;
		//print(file, doc, 0);
		std::string s;
		print(std::back_inserter(s), doc, 0);
		file << s;

		file.close();
		doc.clear();
	}

	API xml_node<>* Serializer::save_entity(xml_node<>* entities, Entity * e)
	{
		xml_node<>* xml_entity;
		nodes.emplace_back(xml_entity);
		xml_entity = doc.allocate_node(node_element, "entity");
		xml_entity->append_attribute(doc.allocate_attribute("id", e->entity->id.c_str()));
		xml_entity->append_node(save_transform(e->transform));
		for (size_t i = 0; i < e->components.size(); i++)
		{
			auto c = dynamic_cast<level_editor::Camera_Component*>(e->components[i]);
			auto l = dynamic_cast<level_editor::Light_Component*>(e->components[i]);
			auto m = dynamic_cast<level_editor::Mesh_Component*>(e->components[i]);
			if(c)
			{
				xml_entity->append_node(save_camera());
			}
			else if (l)
			{
				xml_entity->append_node(save_light());
			}
			else if (m)
			{
				xml_entity->append_node(save_mesh(m));
			}
		}
			
		//entities->append_node(xml_entity);
		//doc.append_node(entities);
		return xml_entity;
	}

	xml_node<>* Serializer::save_transform(level_editor::Transform* t)
	{
		xml_node<>* xml_transform;
		xml_transform = doc.allocate_node(node_element, "component");
		xml_transform->append_attribute(doc.allocate_attribute("id", "transform"));
		xml_node<>* xml_position = doc.allocate_node(node_element, "position");
		xml_node<>* xml_rotation = doc.allocate_node(node_element, "rotation");
		xml_node<>* xml_scale = doc.allocate_node(node_element, "scale");
		xml_transform->append_node(xml_position);
		xml_transform->append_node(xml_rotation);
		xml_transform->append_node(xml_scale);

		//pos
		xml_node<>* x = doc.allocate_node(node_element, "x", save_string(std::to_string(t->e_transform->position.x)));
		xml_position->append_node(x);
		xml_position->append_node(doc.allocate_node(node_element, "y", save_string(std::to_string(t->e_transform->position.y))));
		xml_position->append_node(doc.allocate_node(node_element, "z", save_string(std::to_string(t->e_transform->position.z))));
		//rot																					   
		xml_rotation->append_node(doc.allocate_node(node_element, "x", save_string(std::to_string(t->e_transform->rotation.x))));
		xml_rotation->append_node(doc.allocate_node(node_element, "y", save_string(std::to_string(t->e_transform->rotation.y))));
		xml_rotation->append_node(doc.allocate_node(node_element, "z", save_string(std::to_string(t->e_transform->rotation.z))));
		//sca
		xml_scale->append_node(doc.allocate_node(node_element, "x", save_string(std::to_string(t->e_transform->scale.x))));
		xml_scale->append_node(doc.allocate_node(node_element, "y", save_string(std::to_string(t->e_transform->scale.y))));
		xml_scale->append_node(doc.allocate_node(node_element, "z", save_string(std::to_string(t->e_transform->scale.z))));

		return xml_transform;
	}

	xml_node<>* Serializer::save_light()
	{
		xml_node<>* xml_light;
		xml_light = doc.allocate_node(node_element, "component", " ");
		xml_light->append_attribute(doc.allocate_attribute("id", "light_component"));
		return xml_light;
	}

	xml_node<>* Serializer::save_mesh(level_editor::Mesh_Component * c)
	{
		xml_node<>* xml_mesh;
		xml_mesh = doc.allocate_node(node_element, "component", c->path.c_str());
		xml_mesh->append_attribute(doc.allocate_attribute("id", "mesh_component"));
		return xml_mesh;
	}

	xml_node<>* Serializer::save_camera()
	{
		xml_node<>* xml_camera;
		xml_camera = doc.allocate_node(node_element, "component", " ");
		xml_camera->append_attribute(doc.allocate_attribute("id", "camera_component"));
		return xml_camera;
	}

}
