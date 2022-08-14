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
#include <Box2D/Box2D.h>


namespace engine {
	class Rigibody2d_Component;

	class Physics2d_System : public System
	{
	public:
				
		Physics2d_System() = default;
		Physics2d_System(bool value);

		b2World physics_world;

		/*
		* Update all physics positions and then we check them
		* @param time
		*/
		void run(float) override;

		~Physics2d_System() {};

	};

}