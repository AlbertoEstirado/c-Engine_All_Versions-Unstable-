
#pragma once

#include <camera_controller.hpp>
#include <transform.hpp>
#include <entity.hpp>
#include <scene.hpp>
#include <scene_manager.hpp>0
#include <scene.hpp>


namespace engine
{
	Camera_Controller::Camera_Controller(Entity* e)
	{
		entity = e;

		//Add listeners to the current scene dispatcher
		entity->scene->get_dispatcher().add_listener("r_keydown", *this);
		//position
		entity->scene->get_dispatcher().add_listener("w_keydown", *this);
		entity->scene->get_dispatcher().add_listener("a_keydown", *this);
		entity->scene->get_dispatcher().add_listener("s_keydown", *this);
		entity->scene->get_dispatcher().add_listener("d_keydown", *this);
		//rotation
		entity->scene->get_dispatcher().add_listener("i_keydown", *this);
		entity->scene->get_dispatcher().add_listener("j_keydown", *this);
		entity->scene->get_dispatcher().add_listener("k_keydown", *this);
		entity->scene->get_dispatcher().add_listener("l_keydown", *this);
	}

	void Camera_Controller::update()
	{
	}

	void Camera_Controller::receptor(Message& message)
	{
		if (message.get_Id() == "r_keydown")
		{
			Scene_manager::instance().current_scene->reset_transforms();
		}

		float speed = 0.1f;
		float rotation_speed = 0.01f;

		if (message.get_Id() == "w_keydown")
		{
			entity->transform->position.z -= speed;
		}
		if (message.get_Id() == "a_keydown")
		{
			entity->transform->position.x -= speed;
		}
		if (message.get_Id() == "s_keydown")
		{
			entity->transform->position.z += speed;
		}
		if (message.get_Id() == "d_keydown")
		{
			entity->transform->position.x += speed;
		}

		if (message.get_Id() == "i_keydown")
		{
			entity->transform->rotation.x -= rotation_speed;
		}
		if (message.get_Id() == "j_keydown")
		{
			entity->transform->rotation.y -= rotation_speed;
		}
		if (message.get_Id() == "k_keydown")
		{
			entity->transform->rotation.x += rotation_speed;
		}
		if (message.get_Id() == "l_keydown")
		{
			entity->transform->rotation.y += rotation_speed;
		}
		
	}

}