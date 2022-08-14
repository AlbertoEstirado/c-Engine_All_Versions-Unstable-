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

#include "entity.hpp"
#include "controller.hpp"
#include "dispatcher.hpp"
#include "contact_listener_component.hpp"

namespace engine
{
	class Joint_Component;
	class Rigibody2d_Component;

	class World_Controller : public Controller, public Contact_Listener_Component
	{

	public:

		Entity* entity = nullptr;

		Entity* coche = nullptr;
		Rigibody2d_Component* rb = nullptr;
		Joint_Component* jointSuelo = nullptr;
		Joint_Component* jointSueloDer = nullptr;
		Rigibody2d_Component* goalSensor = nullptr;
		Rigibody2d_Component* win = nullptr;

		World_Controller(Entity * e);

		/**
		* @brief Run behaviours of the entity
		*/
		void update() override;
		void BeginContact(b2Contact* contact) override;

	};

}
