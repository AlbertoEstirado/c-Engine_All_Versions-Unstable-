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

#include <component.hpp>
#include <Model.hpp>
#include <Model_Obj.hpp>
#include <renderer_system.hpp>

namespace engine
{
	class Render_Component : public Component
	{
	public:

		virtual glt::Node& get_node() = 0;			//< Reference to the node so we can get it on the system
		
	};
}

