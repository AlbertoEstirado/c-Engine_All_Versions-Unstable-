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
#include <engine/elevator_controller.hpp>
#include <engine/rigibody2d_component.hpp>
#include <engine/joint_component.hpp>
#include <engine/scene.hpp>
#include <engine/transform.hpp>
#include <engine/physics2d_system.hpp>

namespace engine
{
	
	Elevator_Controller::Elevator_Controller(Entity* e)
	{
		entity = e;

		coche = Scene_manager::instance().current_scene->get_entity("coche");
		plataforma = Scene_manager::instance().current_scene->get_entity("plataforma");
		rb = plataforma->get_component<Rigibody2d_Component>();
	}

	void Elevator_Controller::update()
	{

		if (coche->get_transform()->get_position_x() > 5)
		{
			if (rb->body->GetTransform().p.y < -6.7)
			{
				float y = rb->body->GetPosition().y + 0.1f;
				rb->body->SetTransform({ rb->body->GetPosition().x, y }, rb->body->GetAngle());
			}
		}

		if (coche->get_transform()->get_position_x() > -3 && coche->get_transform()->get_position_x() < -1)
		{
			if (rb->body->GetTransform().p.y > -7 && rb->body->GetTransform().p.y < 5)
			{
				float y = rb->body->GetPosition().y + 0.05f;
				rb->body->SetTransform({ rb->body->GetPosition().x, y }, rb->body->GetAngle());
				coche->get_component<Rigibody2d_Component>()->body->SetLinearVelocity({ 0, 0 });

			}
		}
	}


}