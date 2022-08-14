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

#include <controller.hpp>
#include <entity.hpp>
#include <dispatcher.hpp>
#include <collision_handler.hpp>

namespace engine
{
	class Joint3d_Component;
	

	class Payer_Movement_Controller: public Controller, public Dispatcher::Listener
	{
	public:

		Joint3d_Component* delDer;
		Joint3d_Component* delIzq;
		Joint3d_Component* trasDer;
		Joint3d_Component* trasIzq;

		Joint3d_Component* lanzador;

		Entity* ball;

		Payer_Movement_Controller(Entity* e);
		
		void update() override;
		void receptor(Message& message) override;

	};

}
