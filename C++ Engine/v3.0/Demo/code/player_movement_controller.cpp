/**
*
* @author Alberto Estirado L?pez
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
#include <box_collider_component.hpp>
#include <collision_handler.hpp>
#include <joint_component.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>
#include <joint3d_component.hpp>
#include <rigidbody3d_component.hpp>

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
		entity->scene->get_dispatcher().add_listener("q_keydown", *this);

		entity->scene->get_dispatcher().add_listener("w_keyup", *this);
		entity->scene->get_dispatcher().add_listener("a_keyup", *this);
		entity->scene->get_dispatcher().add_listener("s_keyup", *this);
		entity->scene->get_dispatcher().add_listener("d_keyup", *this);
		entity->scene->get_dispatcher().add_listener("q_keyup", *this);

		delDer = entity->scene->get_entity("delanteraDer")->get_component<Joint3d_Component>();
		delIzq = entity->scene->get_entity("delanteraIzq")->get_component<Joint3d_Component>();
		trasDer = entity->scene->get_entity("traseraDer")->get_component<Joint3d_Component>();
		trasIzq = entity->scene->get_entity("traseraIzq")->get_component<Joint3d_Component>();
		lanzador = entity->scene->get_entity("lanzador")->get_component<Joint3d_Component>();
		lanzador->constraint->setLimit(0, 90);

		ball = entity->scene->get_entity("ball");
	}

	void Payer_Movement_Controller::update()
	{


	}


	void Payer_Movement_Controller::receptor(Message& message)
	{
		float speed = 10;

		if (message.get_Id() == "w_keydown")
		{
			delDer->constraint->enableAngularMotor(true, -speed, 10);
			delIzq->constraint->enableAngularMotor(true, -speed, 10);
			trasDer->constraint->enableAngularMotor(true, -speed, 10);
			trasIzq->constraint->enableAngularMotor(true, -speed, 10);
		}
		if (message.get_Id() == "a_keydown")
		{
			delDer->constraint->enableAngularMotor(true, -speed, 10);
			trasDer->constraint->enableAngularMotor(true, -speed, 10);
			delIzq->constraint->enableAngularMotor(true, speed, 10);
			trasIzq->constraint->enableAngularMotor(true, speed, 10);
		
		}
		if (message.get_Id() == "s_keydown")
		{
			delDer->constraint->enableAngularMotor(true, speed, 10);
			delIzq->constraint->enableAngularMotor(true, speed, 10);
			trasDer->constraint->enableAngularMotor(true, speed, 10);
			trasIzq->constraint->enableAngularMotor(true, speed, 10);
		}
		if (message.get_Id() == "d_keydown")
		{
			delDer->constraint->enableAngularMotor(true, speed, 10);
			delIzq->constraint->enableAngularMotor(true, -speed, 10);
			trasDer->constraint->enableAngularMotor(true, speed, 10);
			trasIzq->constraint->enableAngularMotor(true, -speed, 10);
		}
		
		if (message.get_Id() == "q_keydown")  //Posicionamos la espera justo para que colisione con el lanzador
		{
			btTransform transform;
			transform.setOrigin(btVector3(entity->transform->position.x+1, entity->transform->position.y+1.5f, entity->transform->position.z));
			ball->get_component<Rigidbody3d_Component>()->body->setAngularVelocity(btVector3(0, 0, 0));
			ball->get_component<Rigidbody3d_Component>()->body->setWorldTransform(transform);
			lanzador->constraint->enableAngularMotor(true, 50, 30);
		}
		if (message.get_Id() == "q_keyup")
		{
			lanzador->constraint->enableAngularMotor(true, -50, 30);
		}
		
		if (message.get_Id() == "w_keyup")
		{
			delDer->constraint->enableAngularMotor(true, 0, 10);
			delIzq->constraint->enableAngularMotor(true, 0, 10);
			trasDer->constraint->enableAngularMotor(true, 0, 10);
			trasIzq->constraint->enableAngularMotor(true, 0, 10);
		}
		if (message.get_Id() == "a_keyup")
		{
			delDer->constraint->enableAngularMotor(true, 0, 10);
			delIzq->constraint->enableAngularMotor(true, 0, 10);
			trasDer->constraint->enableAngularMotor(true, 0, 10);
			trasIzq->constraint->enableAngularMotor(true, 0, 10);
		}
		if (message.get_Id() == "s_keyup")
		{
			delDer->constraint->enableAngularMotor(true, 0, 10);
			delIzq->constraint->enableAngularMotor(true, 0, 10);
			trasDer->constraint->enableAngularMotor(true, 0, 10);
			trasIzq->constraint->enableAngularMotor(true, 0, 10);
		}
		if (message.get_Id() == "d_keyup")
		{
			delDer->constraint->enableAngularMotor(true, 0, 10);
			delIzq->constraint->enableAngularMotor(true, 0, 10);
			trasDer->constraint->enableAngularMotor(true, 0, 10);
			trasIzq->constraint->enableAngularMotor(true, 0, 10);
		}
	}

}