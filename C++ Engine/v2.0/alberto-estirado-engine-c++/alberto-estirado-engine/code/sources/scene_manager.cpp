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

#include <scene_manager.hpp>
#include <scene.hpp>

namespace engine
{
	Scene_manager::Scene_manager()
	{
		//scenes.resize(0);
	}

	void Scene_manager::add_scene(Scene* newscene)
	{
		scenes.push_back(newscene);
	}

	void Scene_manager::initialize()
	{
		if(scenes.size() <= 0)
		{
			std::cout << "There is no scene created!";
			return;
		}
		else
		{
			current_scene = scenes[0];
		}
	}

	void Scene_manager::run_scene(Scene * scene)
	{
		current_scene = scene;
		scene->load_scene();
	}


}
