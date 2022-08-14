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

#include <player_movement_controller.hpp>
#include <transform.hpp>
#include <entity.hpp>
#include <scene.hpp>

namespace engine
{
	Payer_Movement_Controller::Payer_Movement_Controller(Entity* e)
	{
		entity = e;
		speed = 0.05;
		dir[0] = 0;
		dir[1] = 0;

		//Add listeners to the current scene dispatcher
		entity->scene->get_dispatcher().add_listener("w_keydown", *this);
		entity->scene->get_dispatcher().add_listener("a_keydown", *this);
		entity->scene->get_dispatcher().add_listener("s_keydown", *this);
		entity->scene->get_dispatcher().add_listener("d_keydown", *this);
									   
		entity->scene->get_dispatcher().add_listener("w_keyup", *this);
		entity->scene->get_dispatcher().add_listener("a_keyup", *this);
		entity->scene->get_dispatcher().add_listener("s_keyup", *this);
		entity->scene->get_dispatcher().add_listener("d_keyup", *this);
	}

	void Payer_Movement_Controller::update()
	{
		Transform* t = entity->get_transform();

		t->position.x += speed * dir[0];
		t->position.z += speed * dir[1];

		t->rotation.y += 0.02;
		t->rotation.z += 0.02;

		Transform* t2 = Scene_manager::instance().current_scene->get_entity("moon")->get_transform();

		t2->rotation.z += 0.05;
	}

	void Payer_Movement_Controller::receptor(Message& message)
	{
		if (message.get_Id() == "w_keydown")
		{
			dir[1] = -1;
		}
		if (message.get_Id() == "a_keydown")
		{
			dir[0] = -1;
		}
		if (message.get_Id() == "s_keydown")
		{
			dir[1] = 1;
		}
		if (message.get_Id() == "d_keydown")
		{
			dir[0] = 1;
		}


		if (message.get_Id() == "w_keyup")
		{
			dir[1] = 0;
		}
		if (message.get_Id() == "a_keyup")
		{
			dir[0] = 0;
		}
		if (message.get_Id() == "s_keyup")
		{
			dir[1] = 0;
		}
		if (message.get_Id() == "d_keyup")
		{
			dir[0] = 0;
		}
	}

}
