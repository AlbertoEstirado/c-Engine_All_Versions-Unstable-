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


#include <engine/entity.hpp>
#include <engine/controller.hpp>
#include <engine/ballsholder_controller.hpp>
#include <engine/rigibody2d_component.hpp>
#include <engine/joint_component.hpp>
#include <engine/scene.hpp>
#include <engine/transform.hpp>
#include <engine/physics2d_system.hpp>

namespace engine
{
	
	Ballsholder_Controller::Ballsholder_Controller(Entity* e)
	{
		entity = e;

		Scene_manager::instance().current_scene->get_dispatcher().add_listener("r_keyup", *this);


		container = Scene_manager::instance().current_scene->get_entity("jointsujetapelotas")->get_component<Joint_Component>();
		container->joint->EnableLimit(true);
		container->joint->SetLimits(0, 90);

		coche = Scene_manager::instance().current_scene->get_entity("coche");
		
		container = Scene_manager::instance().current_scene->get_entity("jointsujetapelotas")->get_component<Joint_Component>();
		
	}

	void Ballsholder_Controller::update()
	{

		if (coche->get_transform()->get_position_x() > 5)
		{
			container->joint->EnableLimit(false);
		}

	}

	void Ballsholder_Controller::receptor(Message& message)
	{

		if (message.get_Id() == "r_keyup")
		{
			container->joint->EnableLimit(true);
			container->joint->SetLimits(0, 90);
		}

	}
}