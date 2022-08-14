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
#include <engine/component.hpp>

namespace level_editor
{
	class Component
	{
	public:

		engine::Component * e_component = nullptr;		//< Referencia al componente de tipo del engine
			
		std::string id;									//< Id para representar luego en por Qt los componentes

		Component() = default;

		virtual ~Component() = default;

	};

}