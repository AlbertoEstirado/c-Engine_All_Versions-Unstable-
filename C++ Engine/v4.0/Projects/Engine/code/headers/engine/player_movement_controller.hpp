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

#include "controller.hpp"
#include "entity.hpp"
#include "dispatcher.hpp"
#include "collision_handler.hpp"

namespace engine
{
	class Joint_Component;

	class Payer_Movement_Controller: public Controller, public Dispatcher::Listener
	{
	public:

		float speed, maleteroSpeed;
		bool hasBalls = false;
		Joint_Component* joint = nullptr;

		Payer_Movement_Controller(Entity* e);
		
		void update() override;
		void receptor(Message& message) override;

	};

}
