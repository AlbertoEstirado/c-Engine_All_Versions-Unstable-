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

#pragma once

#include "entity.hpp"
#include <controller.hpp>
#include <dispatcher.hpp>
#include <contact_listener_component.hpp>

namespace engine
{
	class Joint_Component;
	class Rigibody2d_Component;

	class Elevator_Controller : public Controller
	{

	public:

		Entity* entity = nullptr;

		Entity* coche = nullptr;
		Entity* plataforma = nullptr;
		Rigibody2d_Component* rb = nullptr;

		Elevator_Controller(Entity* e);

		/**
		* @brief Run behaviours of the entity
		*/
		void update() override;

	};

}
