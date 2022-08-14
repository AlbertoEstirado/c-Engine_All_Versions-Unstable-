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

#include <joint_component.hpp>
#include <physics2d_system.hpp>
#include <rigibody2d_component.hpp>
#include <entity.hpp>
#include <transform.hpp>

namespace engine
{
	
	Joint_Component::Joint_Component(Entity* e, Physics2d_System & physics2d_system, Rigibody2d_Component * body_a, Rigibody2d_Component* body_b, bool enable_motor)
	{
		b2RevoluteJointDef joint_def;

		joint_def.Initialize(body_a->body, body_b->body, { body_a->entity->get_transform()->get_position_x(), body_a->entity->get_transform()->get_position_y() });

		joint_def.enableMotor = enable_motor;
		joint_def.collideConnected = false;

		joint = dynamic_cast<b2RevoluteJoint*>(physics2d_system.physics_world.CreateJoint(&joint_def));

		joint->SetMaxMotorTorque(175.f);
		
	}

}