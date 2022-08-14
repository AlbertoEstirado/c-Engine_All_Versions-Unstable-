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
#include <LevelEditor/component.hpp>
#include <engine/mesh_component.hpp>

namespace level_editor
{
	class Mesh_Component : public Component
	{

	public:

		std::string path;

		/// <summary>
		/// El constructor creará un componente de Mesh del engine vacio, luego es el editor el que le asigna la entidad a la 
		/// que pertenece.
		/// </summary>
		/// <param name="_path"></param>
		Mesh_Component(std::string _path)
		{
			id = "Mesh_Component";
			e_component = new engine::Mesh_Component(nullptr);
			path = _path;
		}
		~Mesh_Component() = default;

	};

}