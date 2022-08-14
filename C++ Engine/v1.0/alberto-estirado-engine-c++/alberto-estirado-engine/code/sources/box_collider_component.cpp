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

#include <box_collider_component.hpp>
#include <entity.hpp>
#include <transform.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>

namespace engine
{

	Box_Collider_Component::Box_Collider_Component(Entity* e, float scale_x, float scale_z, engine::Collider_Component::Type type = STATIC)
	{
		//Initialice all variables
		entity = e;
		this->type = type;
		collision_handler = nullptr;

		Transform* t = entity->get_transform();

		//Calculate a square base on the scale and position
		x = t->get_position_x() - scale_x / 2;
		y = t->get_position_z() - scale_z / 2;
		width =scale_x;
		height = scale_z;
	}

	void Box_Collider_Component::im_colliding_with(Box_Collider_Component* other)
	{
		float left1 = x;
		float right1 = x + width;
		float bot1 = y;
		float top1 = y + height;
		
		float left2 = other->x;
		float right2 = other->x + other->width;
		float bot2 = other->y;
		float top2 = other->y + other->height;

		//Check if they colliders are colliding

		if ((right1 >= left2 && left1 <= right2 && top1 >= bot2 && bot1 <= top2) ||
			(right2 >= left1 && left2 <= right1 && top2 >= bot1 && bot2 <= top1))
		{
			//If it as a collision handler it will run the function on_collision
			if(collision_handler)
				collision_handler->on_collision(*other);
			
		}

	}

	void Box_Collider_Component::add_collision_handler(Collision_Handler* c)
	{
		collision_handler = c;
	}

}
