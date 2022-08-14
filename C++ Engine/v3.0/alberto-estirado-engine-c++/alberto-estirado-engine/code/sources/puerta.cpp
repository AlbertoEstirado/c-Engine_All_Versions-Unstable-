
#include <puerta.hpp>
#include <transform.hpp>
#include <entity.hpp>
#include <scene.hpp>

namespace engine
{
	Puerta_Controller::Puerta_Controller(Entity* e)
	{
		entity = e;
		hasKey = false;

		entity->scene->get_dispatcher().add_listener("has_key", *this);
	}

	void Puerta_Controller::update()
	{
		if(hasKey)
		{
			entity->transform->position.y += 0.1f;
		}
	}


	void Puerta_Controller::receptor(Message& message)
	{
		if (message.get_Id() == "has_key")
		{
			hasKey = true;
		}
	}
}