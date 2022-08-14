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

#include <engine/physics2d_system.hpp>
#include <engine/component.hpp>
#include <engine/entity.hpp>
#include <engine/transform.hpp>
#include <engine/rigibody2d_component.hpp>

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

}