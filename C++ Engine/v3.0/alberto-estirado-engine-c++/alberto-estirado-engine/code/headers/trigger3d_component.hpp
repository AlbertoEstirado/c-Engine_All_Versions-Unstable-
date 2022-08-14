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

#include <iostream>
#include <component.hpp>
#include <physics3d_system.hpp>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

namespace engine {

	class Trigger3d_Component : public Component {
		~Trigger3d_Component() = default;

	public:

		struct Cube
		{
			float width;
			float height;
			float depth;
		};

		std::shared_ptr< btCollisionShape >		shape;
		std::shared_ptr< btGhostObject >		sensor;

		Trigger3d_Component(Entity* e, Physics3d_System& physics3d_system, const Cube& box);

	};
}