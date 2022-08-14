#pragma once

#include <controller.hpp>
#include <entity.hpp>
#include <dispatcher.hpp>


namespace engine
{
	class Camera_Controller : public Controller, public Dispatcher::Listener
	{
	public:

		Camera_Controller(Entity* e);


		void update() override;
		void receptor(Message& message) override;

	};

}