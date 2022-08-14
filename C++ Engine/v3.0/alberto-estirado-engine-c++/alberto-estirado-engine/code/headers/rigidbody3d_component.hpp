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

namespace engine {

	class Rigidbody3d_Component : public Component {
		~Rigidbody3d_Component() = default;

	public:
		/// <summary>
		/// Stuctura para cuerpos sphericos
		/// </summary>
		struct Sphere
		{
			float radius;
		};

		struct Cube
		{
			float width;
			float height;
			float depth;
		};

		std::shared_ptr< btDefaultMotionState >     state;
		std::shared_ptr< btCollisionShape >			shape;

		std::shared_ptr< btRigidBody > body;		

		Rigidbody3d_Component(Entity* e, Physics3d_System& physics3d_system, float mass);

		/// <summary>
		/// Constructor de Rigidbody de una esfera
		/// </summary>
		/// <param name="e"></param>
		/// <param name="physics3d_system"></param>
		/// <param name="mass">Si el valor es 0 se vuelve estatico</param>
		/// <param name="circle">Radio de la esfera</param>
		Rigidbody3d_Component(Entity* e, Physics3d_System& physics3d_system, float mass, const Sphere& sphere);
		/// <summary>
		/// Constructor de rigidbody de un cubo
		/// </summary>
		/// <param name="e"></param>
		/// <param name="physics3d_system"></param>
		/// <param name="mass">Si el valor es 0 se vuelve estatico</param>
		/// <param name="box">Ancho, alto y largo del cubo</param>
		Rigidbody3d_Component(Entity* e, Physics3d_System& physics3d_system, float mass, const Cube& box);

	};
}