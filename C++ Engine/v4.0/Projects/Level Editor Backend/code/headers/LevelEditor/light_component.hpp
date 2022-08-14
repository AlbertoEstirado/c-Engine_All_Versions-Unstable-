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
#include <engine/light_component.hpp>

namespace level_editor
{
	class Light_Component : public Component
	{
		float intensity;

	public:

		/// <summary>
		/// El constructor creará un componente de Light del engine vacio, luego es el editor el que le asigna la entidad a la 
		/// que pertenece.
		/// </summary>
		/// <param name="_intensity"></param>
		Light_Component(float _intensity)
		{
			id = "Light_Component";
			intensity = _intensity;
			e_component = new engine::Light_Component(nullptr);
		}

	};

}