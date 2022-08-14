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

#include <update.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>
#include <transform.hpp>

namespace engine
{
	
	void Update::run(float time)
	{
		//Scene_manager::instance().current_scene->get_entity("f2")->get_transform()->rotation.z += 0.01f;
		//std::cout << Scene_manager::instance().current_scene->get_entity("camera")->get_transform()->rotation.x << std::endl;
		Scene_manager::instance().current_scene->update(time);
	}
}

