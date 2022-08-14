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

#include <map>
#include <vector>
#include <iostream>


namespace engine
{
	class Scene;

	typedef std::string Id;

	class Scene_manager
	{
	
	public:

		static Scene_manager & instance()			//< Singletone
		{
			static Scene_manager scene_manager;
			return scene_manager;
		}

		std::vector<Scene *> scenes; 				//< List of al scenes

		Scene* current_scene;						//< Scene that will run in the kernel

		void add_scene(Scene* newscene);
		void initialize();
		
		/**
		* @brief Will change current_scene to a new scene
		* @param scene
		*/
		void run_scene(Scene* scene);

	private:

		Scene_manager();

		~Scene_manager() = default;

		Scene_manager(const Scene_manager&) = delete;

	};

}
