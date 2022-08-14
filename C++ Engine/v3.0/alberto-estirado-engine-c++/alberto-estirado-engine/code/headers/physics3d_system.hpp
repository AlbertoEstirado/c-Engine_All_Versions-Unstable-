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
#include <btBulletDynamicsCommon.h>

namespace engine {
	class Rigidbody3d_Component;

	class Physics3d_System : public System
	{
	public:

		float const scalar = 0.5f;

		std::shared_ptr< btDiscreteDynamicsWorld >  dynamicsWorld;				//< Setup del mundo de fisicas de bullet

		btDefaultCollisionConfiguration				collisionConfiguration;
		btCollisionDispatcher						collisionDispatcher;
		btDbvtBroadphase							overlappingPairCache;
		btSequentialImpulseConstraintSolver			constraintSolver;


		Physics3d_System();

		/*
		* Update all physics
		* @param time
		*/
		void run(float) override;


	};

}