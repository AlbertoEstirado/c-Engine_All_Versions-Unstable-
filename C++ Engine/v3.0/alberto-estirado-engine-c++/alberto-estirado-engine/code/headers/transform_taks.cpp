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

#include <transform_task.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>
#include <transform.hpp>
#include <entity.hpp>

namespace engine
{

	void Transform_Task::run(float time)
	{
		Scene_manager::instance().current_scene->update(time);
		for (auto& e : Scene_manager::instance().current_scene->entities)
		{
			e.second->transform->get_transform_matrix();
		}

	}
}

