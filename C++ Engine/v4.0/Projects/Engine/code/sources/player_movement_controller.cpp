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

#include <engine/player_movement_controller.hpp>
#include <engine/transform.hpp>
#include <engine/entity.hpp>
#include <engine/scene.hpp>
#include <engine/joint_component.hpp>


namespace engine
{
	Payer_Movement_Controller::Payer_Movement_Controller(Entity* e)
	{
		entity = e;

		//Add listeners to the current scene dispatcher
		entity->scene->get_dispatcher().add_listener("w_keydown", *this);
		entity->scene->get_dispatcher().add_listener("a_keydown", *this);
		entity->scene->get_dispatcher().add_listener("s_keydown", *this);
		entity->scene->get_dispatcher().add_listener("d_keydown", *this);

		entity->scene->get_dispatcher().add_listener("w_keyup", *this);
		entity->scene->get_dispatcher().add_listener("a_keyup", *this);
		entity->scene->get_dispatcher().add_listener("s_keyup", *this);
		entity->scene->get_dispatcher().add_listener("d_keyup", *this);

		speed = 0;

	}

	void Payer_Movement_Controller::update()
	{
		Transform* t = entity->get_transform();
		Joint_Component* joint = entity->get_component<Joint_Component>();
		if (joint)
			joint->joint->SetMotorSpeed(speed);

		if (speed != 0) std::cout << "s";

	}


	void Payer_Movement_Controller::receptor(Message& message)
	{
		if (message.get_Id() == "w_keydown")
		{
			speed = 130;
		}
		if (message.get_Id() == "a_keydown")
		{
		}
		if (message.get_Id() == "s_keydown")
		{
		}
		if (message.get_Id() == "d_keydown")
		{
		}


		if (message.get_Id() == "w_keyup")
		{
			speed = 0;
		}
		if (message.get_Id() == "a_keyup")
		{
		}
		if (message.get_Id() == "s_keyup")
		{
		}
		if (message.get_Id() == "d_keyup")
		{
		}
	}

}
