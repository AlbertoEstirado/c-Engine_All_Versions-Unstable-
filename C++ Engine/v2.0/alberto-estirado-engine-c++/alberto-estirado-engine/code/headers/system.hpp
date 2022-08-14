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

#include <task.hpp>
#include <vector>
#include <component.hpp>
#include <scene_manager.hpp>

namespace engine 
{
	class System : public Task
	{
	public:

		Scene* scene;							//< Scene where the systen remains

		std::vector<Component*> components;		//< List of all components

		System() = default;

		void initialize(){}
		void run(float time);
		void end(){}

		virtual ~System() = default;

		/*
		* Add component to the system
		* @param Component
		*/
		void add_component(Component*);
	};
}









