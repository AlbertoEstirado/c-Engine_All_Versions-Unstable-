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
#include <engine/transform.hpp>
#include <LevelEditor/component.hpp>

namespace level_editor
{
	class Transform : public Component
	{

	public:
		engine::Transform* e_transform;    //< Transform del engine.

		/// <summary>
		/// Se inicializa el transform del engine.
		/// </summary>
		Transform() 
		{
			id = "Transform";
			e_transform = new engine::Transform(nullptr);
		}

		/// <summary>
		/// Se inicializa el transform del engine.
		/// </summary>
		Transform(engine::Transform * t)
		{
			id = "Transform";
			e_transform = t;
		}

		/// <summary>
		/// Se inicializa el transform del engine.
		/// </summary>
		Transform(engine::Entity* e)
		{
			id = "Transform";
			e_transform = new engine::Transform(e);
		}

		/// <summary>
		/// Se setea la posición.
		/// </summary>
		/// <param name="new_x"></param>
		/// <param name="new_y"></param>
		/// <param name="new_z"></param>
		void set_position(float new_x, float new_y, float new_z)
		{
			e_transform->position.x = new_x;
			e_transform->position.y = new_y;
			e_transform->position.z = new_z;
		}

		/// <summary>
		/// Se setea la rotación.
		/// </summary>
		/// <param name="new_x"></param>
		/// <param name="new_y"></param>
		/// <param name="new_z"></param>
		void set_rotation(float new_x, float new_y, float new_z)
		{
			e_transform->rotation.x = new_x;
			e_transform->rotation.y = new_y;
			e_transform->rotation.z = new_z;
		}

		/// <summary>
		/// Se setea la escala.
		/// </summary>
		/// <param name="new_x"></param>
		/// <param name="new_y"></param>
		/// <param name="new_z"></param>
		void set_scale(float new_x, float new_y, float new_z)
		{
			e_transform->scale.x = new_x;
			e_transform->scale.y = new_y;
			e_transform->scale.z = new_z;
		}
	};

}
