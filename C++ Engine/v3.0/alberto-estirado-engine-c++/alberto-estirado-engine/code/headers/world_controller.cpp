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


#include "entity.hpp"
#include <controller.hpp>
#include <world_controller.hpp>
#include <rigibody2d_component.hpp>
#include <joint_component.hpp>
#include <scene.hpp>
#include <transform.hpp>
#include <physics2d_system.hpp>

namespace engine
{

	World_Controller::World_Controller(Entity* e)
	{
		entity = e;

		coche = Scene_manager::instance().current_scene->get_entity("coche");
		jointSuelo = Scene_manager::instance().current_scene->get_entity("suelomaleter")->get_component<Joint_Component>();
		jointSuelo->joint->EnableLimit(true);
		jointSueloDer = Scene_manager::instance().current_scene->get_entity("maleteroDer")->get_component<Joint_Component>();
		jointSueloDer->joint->EnableLimit(true);

		goalSensor = Scene_manager::instance().current_scene->get_entity("goalSensor")->get_component<Rigibody2d_Component>();

		Scene_manager::instance().current_scene->physics2d_system->physics_world.SetContactListener(this);


	}

	void World_Controller::update()
	{

	}

	void World_Controller::BeginContact(b2Contact* contact)
	{
		if (contact->GetFixtureA()->IsSensor())
		{
			std::cout << "win";
		}
	}

}