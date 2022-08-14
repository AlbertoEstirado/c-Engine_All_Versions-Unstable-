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

#include <trigger3d_component.hpp>
#include <transform.hpp>
#include <entity.hpp>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

namespace engine 
{

	Trigger3d_Component::Trigger3d_Component(Entity* e, Physics3d_System& physics3d_system, const Cube& box)
	{
		entity = e;
		
		shape.reset(new btBoxShape(btVector3(box.width, box.height, box.depth)));

		Transform* t = entity->get_transform();
		btTransform transform;

		transform.setIdentity();
		transform.setOrigin(btVector3(t->position.x, t->position.y, t->position.z));

		sensor.reset(new btGhostObject);

		sensor->setCollisionShape(shape.get());
		sensor->setWorldTransform(transform);
		sensor->setCollisionFlags(sensor->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);

		physics3d_system.dynamicsWorld->getPairCache()->setInternalGhostPairCallback(new btGhostPairCallback());

		physics3d_system.dynamicsWorld->addCollisionObject(sensor.get());
	}


}