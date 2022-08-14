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

#pragma once

#include <rigidbody3d_component.hpp>
#include <transform.hpp>
#include <entity.hpp>

namespace engine
{
	Rigidbody3d_Component::Rigidbody3d_Component(Entity* e, Physics3d_System& physics3d_system, float _mass)
	{
        entity = e;

        shape.reset((new btSphereShape(btScalar(1.))));

        // Create Dynamic Objects.

        Transform * myTrans = e->get_transform();

        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(btVector3(myTrans->get_position_x(), myTrans->get_position_y(), myTrans->get_position_z()));

        btScalar  mass = _mass;
        btVector3 localInertia(0, 0, 0);

        shape->calculateLocalInertia(mass, localInertia);

        // Using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects

        state.reset(new btDefaultMotionState(transform));
        btRigidBody::btRigidBodyConstructionInfo info(mass, state.get(), shape.get(), localInertia);


		body.reset(new btRigidBody(info));

        body->setRestitution(1.0);

        physics3d_system.dynamicsWorld->addRigidBody(body.get());
        physics3d_system.add_component(this);
	}

    Rigidbody3d_Component::Rigidbody3d_Component(Entity* e, Physics3d_System& physics3d_system, float _mass, const Sphere & circle)
    {
        entity = e;

        shape.reset((new btSphereShape(btScalar(circle.radius * physics3d_system.scalar))));

        Transform* myTrans = e->get_transform();
 
        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(btVector3(myTrans->get_position_x(), myTrans->get_position_y(), myTrans->get_position_z()));

        btScalar  mass = _mass;
        btVector3 localInertia(0, 0, 0);
		if (mass != 0) {
			shape->calculateLocalInertia(mass, localInertia);
		}

        state.reset((new btDefaultMotionState(transform)));
        btRigidBody::btRigidBodyConstructionInfo info(mass, state.get(), shape.get(), localInertia);


        body.reset(new btRigidBody(info));

        body->setRestitution(0.2f);

		body->setActivationState(DISABLE_DEACTIVATION);

        physics3d_system.dynamicsWorld->addRigidBody(body.get());
        physics3d_system.add_component(this);
    }

    Rigidbody3d_Component::Rigidbody3d_Component(Entity* e, Physics3d_System& physics3d_system, float _mass, const Cube & cube)
    {
        entity = e;

        shape.reset((new btBoxShape(btVector3(cube.width * physics3d_system.scalar, cube.height * physics3d_system.scalar, cube.depth * physics3d_system.scalar))));

        Transform* myTrans = e->get_transform();

        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(btVector3(myTrans->get_position_x(), myTrans->get_position_y(), myTrans->get_position_z()));

        btScalar  mass = _mass;
        btVector3 localInertia(0, 0, 0);

		if (mass != 0) {
			shape->calculateLocalInertia(mass, localInertia);
		}

        state.reset((new btDefaultMotionState(transform)));
        btRigidBody::btRigidBodyConstructionInfo info(mass, state.get(), shape.get(), localInertia);


        body.reset(new btRigidBody(info));

        body->setRestitution(0.2f);

		body->setActivationState(DISABLE_DEACTIVATION);

        physics3d_system.dynamicsWorld->addRigidBody(body.get());
        physics3d_system.add_component(this);
    }
}