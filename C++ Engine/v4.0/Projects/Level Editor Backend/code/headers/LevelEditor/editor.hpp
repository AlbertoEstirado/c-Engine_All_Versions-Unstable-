/**
*
* @author Alberto Estirado López
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/

/*
#include "scene.hpp"
#include "component.hpp"
#include "transform.hpp"
#include "mesh_component.hpp"
#include "light_component.hpp"
#include "camera_component.hpp"
#include "entity.hpp"


namespace level_editor
{

	class Editor
	{
	public:

		Scene* scene_editing = nullptr;

		void create_scene(std::string name, std::string path)
		{
			scene_editing = new Scene(name, path);
		}

		void add_entity(std::string name)
		{
			scene_editing->entities.insert(std::pair<std::string, Entity>(name, Entity(name)));
		}

		void add_mesh_component(std::string entity_name, std::string path)
		{
			Component * s = (Component*) new Mesh_Component(entity_name, path);
			scene_editing->entities[entity_name].components.push_back(s);
		}

		void add_light_component(std::string entity_name, float intensity)
		{
			Component* s = (Component*) new Light_Component(entity_name, intensity);
			scene_editing->entities[entity_name].components.push_back(s);
		}

		void add_camera_component(std::string entity_name, float fov, float near, float far, float aspect_ratio)
		{
			Component* s = (Component*) new Camera_Component(entity_name, fov, near, far, aspect_ratio);
			scene_editing->entities[entity_name].components.push_back(s);
		}

		void set_entity_position(std::string entity_name, float new_x, float new_y, float new_z)
		{
			scene_editing->entities[entity_name].transform.set_position(new_x, new_y, new_z);
		}

		void set_entity_rotation(std::string entity_name, float new_x, float new_y, float new_z)
		{
			scene_editing->entities[entity_name].transform.set_rotation(new_x, new_y, new_z);
		}

		void set_entity_scale(std::string entity_name, float new_x, float new_y, float new_z)
		{
			scene_editing->entities[entity_name].transform.set_scale(new_x, new_y, new_z);
		}
	};
}*/