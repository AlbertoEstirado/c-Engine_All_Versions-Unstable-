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

#include <physics2d_system.hpp>
#include <component.hpp>
#include <entity.hpp>
#include <transform.hpp>
#include <rigibody2d_component.hpp>

namespace engine {

	Physics2d_System::Physics2d_System(bool value) : physics_world(b2Vec2(0, -10.f))
	{

	}

	void Physics2d_System::run(float delta)
	{
		physics_world.Step(delta, 8, 4);

		for (auto& component : components)
		{
			auto physics_component = dynamic_cast<Rigibody2d_Component*>(component);
			component->entity->transform->position.x = physics_component->body->GetPosition().x;
			component->entity->transform->position.y = physics_component->body->GetPosition().y;
			component->entity->transform->rotation.z = physics_component->body->GetAngle();
		}
	}

	Rigibody2d_Component::Rigibody2d_Component(Entity* e, Physics2d_System& physics2d_system, bool isStatic, bool isSensor) {

		b2BodyDef bodyDef;

		entity = e;
		if (isStatic) {
			bodyDef.type = b2_staticBody;
		}
		else {
			bodyDef.type = b2_dynamicBody;
		}

		bodyDef.position.Set(
			entity->get_transform()->get_position_x(),
			entity->get_transform()->get_position_y()
		);

		body = physics2d_system.physics_world.CreateBody(&bodyDef);
		physics2d_system.add_component(this);
	}

	Rigibody2d_Component::Rigibody2d_Component(Entity* e, Physics2d_System& physics2d_system, bool isStatic, bool isSensor, const Circle& cirlce)
		: Rigibody2d_Component(e, physics2d_system, isStatic, isSensor)
	{

		b2CircleShape body_shape;
		body_shape.m_radius = cirlce.radius;

		//b2FixtureDef body_fixture;
		//
		//body_fixture.shape = &body_shape;
		//body_fixture.density = 0.10f;
		//body_fixture.restitution = 0.75f;
		//body_fixture.friction = 1.f;
		//body_fixture.isSensor = isSensor;

		body->CreateFixture(&body_shape, 1.f);

		body->GetFixtureList()->SetSensor(isSensor);
		body->GetFixtureList()->SetFriction(1.f);

	}

	Rigibody2d_Component::Rigibody2d_Component(Entity* e, Physics2d_System& physics2d_system, bool isStatic, bool isSensor, const Box& box)
	{
		b2BodyDef bodyDef;

		entity = e;
		if (isStatic) {
			bodyDef.type = b2_staticBody;
		}
		else {
			bodyDef.type = b2_dynamicBody;
		}

		bodyDef.position.Set(
			entity->get_transform()->get_position_x(),
			entity->get_transform()->get_position_y()
		);

		body = physics2d_system.physics_world.CreateBody(&bodyDef);
		physics2d_system.add_component(this);

		b2PolygonShape body_shape;

		body_shape.SetAsBox(box.width, box.height);

		body->CreateFixture(&body_shape, 1.f);
		body->GetFixtureList()->SetSensor(isSensor);
	}

}