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

#include <LevelEditor/API.hpp>
#include <LevelEditor/component.hpp>
#include <engine/camera_component.hpp>

namespace level_editor
{
	class Camera_Component : public level_editor::Component
	{

		float fov;
		float near;
		float far;
		float aspect_ratio;

	public:

		/// <summary>
		/// El constructor creará un componente de camara del engine vacio, luego es el editor el que le asigna la entidad a la 
		/// que pertenece.
		/// </summary>
		/// <param name="_fov"></param>
		/// <param name="_near"></param>
		/// <param name="_far"></param>
		/// <param name="_aspect_ratio"></param>
		/// <returns></returns>
		Camera_Component(float _fov, float _near, float _far, float _aspect_ratio)
		{
			id = "Camera_Component";
			fov = _fov;
			near = _near;
			far = _far;
			aspect_ratio = _aspect_ratio;
			e_component = new engine::Camera_Component(nullptr);
		}

	};

}
