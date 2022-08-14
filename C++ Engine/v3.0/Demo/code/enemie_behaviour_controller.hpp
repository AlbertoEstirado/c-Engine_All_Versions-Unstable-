#pragma once

#include <controller.hpp>
#include <glm/glm.hpp>


namespace engine
{
	class Entity;

	typedef glm::vec3 Vector3;

	class Enemie_Behaviour_Controller : public Controller//, public Dispatcher::Listener
	{
	public:

		float speed;
		Vector3 dir;

		Enemie_Behaviour_Controller(Entity* e);

		void update() override;
		//void receptor(Message& message) override;

	};

}