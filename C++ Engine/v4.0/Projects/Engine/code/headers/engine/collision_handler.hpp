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

namespace engine
{
	class Box_Collider_Component;

	class Collision_Handler
	{
	public:
		virtual void on_collision(Box_Collider_Component& other) = 0;
	};
}