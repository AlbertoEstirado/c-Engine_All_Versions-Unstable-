#include <enemie_behaviour_controller.hpp>
#include <transform.hpp>
#include <scene.hpp>
#include <entity.hpp>


namespace engine
{

	Enemie_Behaviour_Controller::Enemie_Behaviour_Controller(Entity* e)
	{
		entity = e;
		speed = 0.01f;
		dir.x = 0;
		dir.y = 0;
		dir.z = 0;
	}

	void Enemie_Behaviour_Controller::update()
	{
		Transform* my_transform = entity->get_transform();
		Transform* target = entity->scene->get_entity("player")->get_transform();

		dir.x = target->get_position_x() - my_transform->get_position_x();
		dir.z = target->get_position_z() - my_transform->get_position_z();

		dir = glm::normalize(dir);

		my_transform->position.x += speed * dir.x;
		my_transform->position.z += speed * dir.z;
	}

}
