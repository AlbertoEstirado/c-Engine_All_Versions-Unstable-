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

#pragma once

#include <system.hpp>
#include <vector>

namespace engine
{
	class Box_Collider_Component;

	class Collision_System: public System
	{
	public:

		std::vector<Box_Collider_Component*> scene_colliders;				//< All colliders on the scene
		std::vector<Box_Collider_Component*> scene_dynamic_colliders;		//< Colliders that will move, these are the colliders for which we will check collisions

		Collision_System() = default;
		
		/*
		* Update all collision positions and then we check them
		* @param time
		*/
		void run(float) override;
		
		/*
		* Add a collider to the list, if is static it will be only added to scene_colliders	
		* @param box_collider_component
		*/
		void add_collider(Box_Collider_Component*);

		~Collision_System() {};


	};

}
