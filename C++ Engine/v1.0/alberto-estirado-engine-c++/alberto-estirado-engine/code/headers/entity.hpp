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

#ifndef ENTITY
#define ENTITY

#include <vector>
#include <iostream>
#include "component.hpp"

#pragma once

namespace engine
{
	class Transform;
	class Scene;
	

	class Entity
	{
	public:

		std::string id;							//< Id of the entity

		std::vector<Component*> components;		//< List of all the diferent components

		Transform* transform = nullptr;			//< Transform os the entity

		Scene* scene = nullptr;					//< Current scene where the entity remains

		Entity();
		Entity(std::string& id, Scene* scene);

		/**
		* @brief Entity constructor, needs an id and a transform
		* @param id
		* @param transform
		*/
		Entity(std::string & id, Transform* transform);
		Entity(std::string & id);

		/**
		* @brief Functition to add new components to the list
		* @param new_component
		*/
		void add_component(Component* new_component);

		/**
		* @brief Functition to establish a transform
		* @param new_component
		*/
		void add_transform(Transform* new_component);
		
		/**
		* @brief Returns the transform entity
		*/
		Transform* get_transform();

		/**
		* @brief Returns the component of the indicated type in case the entity contains it
		*/
		template< typename T >
		T* get_component()
		{
			for (auto& component : components)
			{
				auto casted_component = dynamic_cast<T*>(component);
		
				if (casted_component)
				{
					return casted_component;
				}
			}
		
			return nullptr;
		}
		

	};
}

#endif
