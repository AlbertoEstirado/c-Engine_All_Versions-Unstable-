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


#include "llave.hpp"

#include <llave.hpp>
#include <trigger3d_component.hpp>
#include <transform.hpp>
#include <scene.hpp>
#include <scene_manager.hpp>
#include <puerta.hpp>

namespace engine
{
	Llave_Controller::Llave_Controller(Entity* e)
	{
		entity = e;
		trigger = e->get_component<Trigger3d_Component>();
		done = false;
	}

	void Llave_Controller::update()
	{
		for (size_t i = 0; i < trigger->sensor->getNumOverlappingObjects(); i++)
		{
			if (trigger->sensor->getOverlappingObject(i) && !done)
			{
				done = true;
				entity->transform->position.y = 0;
				btTransform transform;
				transform.setOrigin(btVector3(entity->transform->position.x, entity->transform->position.y, entity->transform->position.z));
				trigger->sensor->setWorldTransform(transform);
				
				Message* new_input_message = new Message("has_key");
				Scene_manager::instance().current_scene->dispatcher->multicast(*new_input_message);
		
			}
		}
	}

	void Llave_Controller::receptor(Message& message)
	{
	}
}