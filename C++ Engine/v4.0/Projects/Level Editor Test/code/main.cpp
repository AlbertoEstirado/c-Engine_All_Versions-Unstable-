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


#include <LevelEditor/serializer.hpp>
#include <LevelEditor/scene.hpp>
#include <LevelEditor/editor_controller.hpp>
#include <LevelEditor/component.hpp>
#include <LevelEditor/camera_component.hpp>
#include <LevelEditor/transform.hpp>
#include <LevelEditor/light_component.hpp>
#include <engine/camera_component.hpp>
#include <filesystem>
#include <iostream>

#undef main			// ESTO ES PORQUE SDL2 DEFINE EN SU CABECERA UNA MACRO LLAMADA main QUE CONVIERTE EL NOMBRE DE LA FUNCIÓN EN SDL_main...

int main()
{
    std::cout << "Test\n";
	level_editor::Serializer s = level_editor::Serializer();

	level_editor::Scene scene("new_scene", "");
	level_editor::Editor_Controller* editor = new level_editor::Editor_Controller(scene);

	editor->add_entity("camera");
	editor->add_transform_to("camera", new level_editor::Transform());
	editor->get_entity_add_component("camera", new level_editor::Camera_Component(0.f, 0.f, 0.f, 0.f));

	editor->add_entity("light");
	editor->add_transform_to("light", new level_editor::Transform());
	editor->get_entity_add_component("light", new level_editor::Light_Component(1.f));
	
	s.save_scene(editor->scene);

	return 0;
}

