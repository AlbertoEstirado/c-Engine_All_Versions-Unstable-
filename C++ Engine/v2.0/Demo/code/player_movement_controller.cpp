#include <player_movement_controller.hpp>
#include <transform.hpp>
#include <entity.hpp>
#include <scene.hpp>
#include <box_collider_component.hpp>
#include <collision_handler.hpp>
#include <joint_component.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>

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

		entity->scene->get_dispatcher().add_listener("r_keydown", *this);

		entity->scene->get_dispatcher().add_listener("w_keyup", *this);
		entity->scene->get_dispatcher().add_listener("a_keyup", *this);
		entity->scene->get_dispatcher().add_listener("s_keyup", *this);
		entity->scene->get_dispatcher().add_listener("d_keyup", *this);

		speed = 20;
		joint = entity->get_component<Joint_Component>();
	}

	void Payer_Movement_Controller::update()
	{
		Transform* t = entity->get_transform();
		
		Joint_Component* maletero = Scene_manager::instance().current_scene->get_entity("maleteroIzq")->get_component<Joint_Component>();
		maletero->joint->SetMaxMotorTorque(500);
		maletero->joint->SetLimits(90, 100);

		if(maletero)
		{
			maletero->joint->SetMotorSpeed(maleteroSpeed);
		}

		if (entity->get_transform()->get_position_x() > 5)
		{
			hasBalls = true;
		}

	}

	
	void Payer_Movement_Controller::receptor(Message& message)
	{
		if (message.get_Id() == "d_keydown" )
		{
			joint->joint->SetMotorSpeed(speed);
		}
		if (message.get_Id() == "r_keydown" )
		{
			Scene_manager::instance().current_scene->reset_transforms();
		}
		if (message.get_Id() == "a_keydown")
		{
			joint->joint->SetMotorSpeed(-speed);
		}
		if (message.get_Id() == "s_keydown")
		{
			maleteroSpeed = 1;
		}
		if (message.get_Id() == "w_keydown")
		{
			maleteroSpeed = -1;
		}


		if (message.get_Id() == "d_keyup")
		{
			joint->joint->SetMotorSpeed(0);
		}
		if (message.get_Id() == "w_keyup")
		{
			maleteroSpeed = 0;
		}
		if (message.get_Id() == "a_keyup")
		{
			joint->joint->SetMotorSpeed(0);
		}
		if (message.get_Id() == "s_keyup")
		{
			maleteroSpeed = 0;
		}
	}

}