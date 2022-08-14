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

#include <render.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>

namespace engine
{
	
	void Render::initialize()
	{
		
	}

	void Render::run(float time)
	{
		Scene_manager::instance().current_scene->render();
	}

	void Render::end()
	{
		Kernel::instance().stop_kernel();
	}
}

