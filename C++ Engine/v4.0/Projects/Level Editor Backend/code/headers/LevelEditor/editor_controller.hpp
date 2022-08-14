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

#pragma once

#include <LevelEditor/entity.hpp>
#include <LevelEditor/scene.hpp>
#include <LevelEditor/serializer.hpp>

namespace level_editor
{
	class Editor_Controller
	{
	public:

		level_editor::Scene scene;
		level_editor::Serializer* serializer;

		/// <summary>
		/// Constructor del editor en el que se crea una scena y un serializador
		/// </summary>
		/// <param name="e"></param>
		Editor_Controller(level_editor::Scene& e)
		{
			scene = e;
			serializer = new level_editor::Serializer();
		}

		/// <summary>
		/// Añade una nueva entidad a la escena.
		/// </summary>
		/// <param name="name"></param>
		void add_entity(std::string name)
		{
			scene.add_entity(new level_editor::Entity(name));
		}

		/// <summary>
		/// Añade un transform a la entidad.
		/// </summary>
		/// <param name="e"></param>
		/// <param name="new_c"></param>
		void add_transform_to(std::string e, Transform* new_c)
		{
			level_editor::Entity* entity = scene.get_entity(e);
			entity->transform = new_c;
		}

		/// <summary>
		/// Añade un componente a la entidad si es que se encuentra en la escena.
		/// </summary>
		/// <param name="e"></param>
		/// <param name="new_c"></param>
		void get_entity_add_component(std::string e, level_editor::Component * new_c)
		{
			level_editor::Entity* entity = scene.get_entity(e);
			if (entity) {
				entity->add_component(new_c);
			}
		}

		/// <summary>
		/// Setea la posicion del transform.
		/// </summary>
		/// <param name="e"></param>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="z"></param>
		void set_pos_transform_values(std::string e, float x, float y, float z)
		{
			level_editor::Entity* entity = scene.get_entity(e);
			entity->transform->set_position(x,y,z);
		}

		/// <summary>
		/// Setea la rotacion del transform.
		/// </summary>
		/// <param name="e"></param>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="z"></param>
		void set_rot_transform_values(std::string e, float x, float y, float z)
		{
			level_editor::Entity* entity = scene.get_entity(e);
			entity->transform->set_rotation(x, y, z);
		}

		/// <summary>
		/// Setea la escala del transform.
		/// </summary>
		/// <param name="e"></param>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="z"></param>
		void set_sca_transform_values(std::string e, float x, float y, float z)
		{
			level_editor::Entity* entity = scene.get_entity(e);
			entity->transform->set_scale(x, y, z);
		}

		/// <summary>
		/// Llama al serializador y le pasa la scena para parsearla a xml.
		/// </summary>
		void parse_scene()
		{
			serializer->save_scene(scene);
		}

		/// <summary>
		/// Devuelve un string con todas las entidades de la escena.
		/// </summary>
		/// <returns></returns>
		std::string get_entities()
		{
			std::string scene_entities;
			for (size_t i = 0; i < scene.entities.size(); i++)
			{
				scene_entities.append(scene.entities[i]->entity->id + "\n");
			}
			return scene_entities;
		}

		/// <summary>
		/// Recive el nombre de una entidad, si se encuentra una entidad en la escena con ese nombre
		/// se crea un string con todos los ids de los componentes.
		/// </summary>
		/// <param name="entity"></param>
		/// <returns></returns>
		std::string get_components(std::string entity)
		{
			std::string components;
			level_editor::Entity* e = scene.get_entity(entity);
			if(e)
			{
				for (size_t i = 0; i < e->components.size(); i++)
				{
					components.append(e->components[i]->id += "\n");
				}

				return components;
			}
			else
			{
				return "";
			}

		}
	};
}