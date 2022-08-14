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

#include <iostream>
#include <vector>
#include <LevelEditor/entity.hpp>

namespace level_editor
{
	class Scene
	{
	public:

		std::string name;					//< Nombre de la escena.

		std::string xml_path;				//< Path donde se guarda el xml.

		std::vector<Entity *> entities;		//< Lista de las entidades de las escenas.

		Scene() = default;

		/// <summary>
		/// Se le asigna un nombre a la nueva escena y un path donde guardarse. 
		/// Se resetea lan entidades.
		/// </summary>
		/// <param name="scene_name"></param>
		/// <param name="path"></param>
		Scene(std::string scene_name, std::string path)
		{
			name = scene_name;
			xml_path = path;
			entities.resize(0);
		}

		/// <summary>
		/// Añade una entidad nueva a la escena.
		/// </summary>
		/// <param name="new_e"></param>
		void add_entity(Entity * new_e)
		{
			entities.push_back(new_e);
		}

		/// <summary>
		/// Retorna la entidad si se encuentra en la escena.
		/// </summary>
		/// <param name="e"></param>
		/// <returns></returns>
		Entity * get_entity(std::string e)
		{
			for (size_t i = 0; i < entities.size(); i++)
			{
				if(entities[i]->entity->id == e)
				{
					return entities[i];
				}
			}
			return nullptr;
		}


	};

}