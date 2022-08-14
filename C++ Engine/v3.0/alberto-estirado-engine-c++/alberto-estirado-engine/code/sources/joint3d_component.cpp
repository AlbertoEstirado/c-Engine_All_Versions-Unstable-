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

#include <joint3d_component.hpp>
#include <entity.hpp>
#include <rigidbody3d_component.hpp>

namespace engine
{
	Joint3d_Component::Joint3d_Component(Entity* e, Physics3d_System& physics3d_system, Rigidbody3d_Component* other, btVector3 other_axis)
	{
		entity = e;
		
		//La entidad que quiera tener un joint debe de tener un RigidBody3d_Component
		Rigidbody3d_Component* rb = entity->get_component<Rigidbody3d_Component>();
		if(rb == nullptr)
		{
			std::cout << "Esta entidad necesita un RigidBody3d_Component para hacer uso de un JointComponent" << std::endl;
		}
		
		constraint = std::make_shared< btHingeConstraint >(*rb->body, *other->body, btVector3(0, 0, 0), other_axis, btVector3(0, 0, 1), btVector3(0, 0, 1));
		
		constraint->enableAngularMotor(true, 0, 10);
		
		physics3d_system.dynamicsWorld->addConstraint(constraint.get());
	}
}