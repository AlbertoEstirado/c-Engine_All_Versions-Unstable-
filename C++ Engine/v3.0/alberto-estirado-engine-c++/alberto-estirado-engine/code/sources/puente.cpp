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


#include <puente.hpp>
#include <trigger3d_component.hpp>
#include <transform.hpp>
#include <rigidbody3d_component.hpp>
#include <physics3d_system.hpp>

namespace engine
{
	Puente_Controller::Puente_Controller(Entity* e)
	{
		entity = e;
		trigger = e->get_component<Trigger3d_Component>();
	}

	void Puente_Controller::update()
	{
		int x = trigger->sensor->getNumOverlappingObjects();
		for (size_t i = 0; i < trigger->sensor->getNumOverlappingObjects(); i++)
		{
			if (trigger->sensor->getOverlappingObject(i))
			{
				if(entity->transform->get_position_x() < 5)
				{
					btTransform physics_transform;
		
					entity->get_component<Rigidbody3d_Component>()->body->getMotionState()->getWorldTransform(physics_transform);
					glm::mat4 graphics_transform;
					physics_transform.getOpenGLMatrix(glm::value_ptr(graphics_transform));
					physics_transform.getOrigin()[0] += 0.01f;
					Transform* t = entity->get_transform();
					entity->get_component<Rigidbody3d_Component>()->body->getMotionState()->setWorldTransform(physics_transform);
				}
			}
		}

	}

	void Puente_Controller::receptor(Message& message)
	{
	}
}