#pragma once

#include <controller.hpp>
#include <entity.hpp>
#include <dispatcher.hpp>


namespace engine
{
	class Payer_Movement_Controller : public Controller, public Dispatcher::Listener
	{
	public:

		float speed;
		int dir[2];
		bool hasBalls = false;

		Payer_Movement_Controller(Entity* e);


		void update() override;
		void receptor(Message& message) override;

	};

}
