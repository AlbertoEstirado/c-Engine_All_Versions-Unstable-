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
#include <LevelEditor/component.hpp>
#include <LevelEditor/transform.hpp>
#include <engine/entity.hpp>

namespace level_editor
{
	class Entity
	{
	public:

		std::vector<Component *> components;			//< Lista de componentes
		engine::Entity* entity = nullptr;				//< Referencia a una entidad del engine

		level_editor::Transform* transform = nullptr;	//< Referencia al transform (todas las entidades lo tienen)

		/// <summary>
		/// Se inicializa la entidad del engine y se crea un transform.
		/// </summary>
		/// <param name="entity_name"></param>
		Entity(std::string entity_name)
		{
			entity = new engine::Entity(entity_name);
			transform = new level_editor::Transform(entity);
		}

		/// <summary>
		/// Añade un componente a la entidad, además le asigan al componente a la entidad a la que pertenece.
		/// </summary>
		/// <param name="new_c"></param>
		void add_component(Component * new_c)
		{
			new_c->e_component->entity = entity;
			components.push_back(new_c);
		}

	};

}