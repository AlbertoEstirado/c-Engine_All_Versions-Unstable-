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

#include <collision_system.hpp>
#include <collider_component.hpp>
#include <box_collider_component.hpp>
#include <transform.hpp>
#include <entity.hpp>

namespace engine
{
	void Collision_System::run(float time = 0)
	{
		//Actualize all collider positions
		for (size_t i = 0; i < scene_dynamic_colliders.size(); i++)
		{
			Transform* t = scene_dynamic_colliders[i]->entity->get_transform();

			scene_dynamic_colliders[i]->x = t->get_position_x() - scene_dynamic_colliders[i]->width / 2;
			scene_dynamic_colliders[i]->y = t->get_position_z() - scene_dynamic_colliders[i]->height / 2;
		}

		//Check dynamic colliders with all colliders
		for (size_t i = 0; i < scene_dynamic_colliders.size(); i++)
		{
			for (size_t j = i+1; j < scene_colliders.size(); j++)
			{
				scene_dynamic_colliders[i]->im_colliding_with(scene_colliders[j]);
				scene_colliders[j]->im_colliding_with(scene_dynamic_colliders[i]);
			}
		}
	}

	void Collision_System::add_collider(Box_Collider_Component* new_collider)
	{

		//We check the type so we can added to the corresponding list
		if(new_collider->type == engine::Collider_Component::Type::DYNAMIC)
		{
			scene_colliders.push_back(new_collider);
			scene_dynamic_colliders.push_back(new_collider);
		}
		else
		{
			scene_colliders.push_back(new_collider);
		}
	}

}
