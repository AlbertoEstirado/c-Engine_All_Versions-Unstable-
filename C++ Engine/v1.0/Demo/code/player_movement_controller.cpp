#include <player_movement_controller.hpp>
#include <transform.hpp>
#include <entity.hpp>
#include <scene.hpp>
#include <box_collider_component.hpp>
#include <collision_handler.hpp>

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

		Box_Collider_Component * c = entity->get_component<Box_Collider_Component>();
		c->add_collision_handler(this);
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

	void Payer_Movement_Controller::on_collision(Box_Collider_Component& other)
	{
		if(other.entity->id == "enemie1" || 
		   other.entity->id == "enemie2" || 
		   other.entity->id == "enemie3" || 
		   other.entity->id == "enemie4" )
		{
			Scene_manager::instance().current_scene->reset_transforms();
		}

		if(other.entity->id == "wall"  ||
		   other.entity->id == "wall1" || 
		   other.entity->id == "wall2" )
		{
			if(dir[0] == 1)
			{
				canMoveRight = false;
				dir[0] = 0;
			}
			if (dir[1] == -1)
			{
				canMoveDown = false;
				dir[1] = 0;
			}
			if (dir[0] == -1)
			{
				canMoveLeft = false;
				dir[0] = 0;
			}
			if (dir[1] == 1)
			{
				canMoveUp = false;
				dir[1] = 0;
			}
		}
	}

	void Payer_Movement_Controller::receptor(Message& message)
	{
		if (message.get_Id() == "w_keydown" && canMoveDown)
		{
			dir[1] = -1;
			canMoveUp = true;
		}
		if (message.get_Id() == "a_keydown" && canMoveLeft)
		{
			dir[0] = -1;
			canMoveRight = true;
		}
		if (message.get_Id() == "s_keydown" && canMoveUp)
		{
			dir[1] = 1;
			canMoveDown = true;
		}
		if (message.get_Id() == "d_keydown" && canMoveRight)
		{
			dir[0] = 1;
			canMoveLeft = true;
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