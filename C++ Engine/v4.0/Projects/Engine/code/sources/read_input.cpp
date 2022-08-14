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

#include <engine/read_input.hpp>
#include <engine/scene_manager.hpp>
#include <engine/scene.hpp>

namespace engine
{

	void Read_input::run(float time)
	{
		//Read the inputs from the current window
		window->handle_events();
	}
}

