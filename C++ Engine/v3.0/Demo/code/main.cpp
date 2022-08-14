/**
*
* @author Alberto Estirado L?pez
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/

#include <SDL.h>
#include <ciso646>
#include <iostream>

#include <kernel.hpp>
#include <scene.hpp>
#include <render.hpp>
#include <read_input.hpp>
#include <update.hpp>
#include <transform.hpp>
#include <Light.hpp>
#include <Cube.hpp>
#include <keyboardcontrol_component.hpp>
#include "player_movement_controller.hpp"
#include "enemie_behaviour_controller.hpp"
#include <box_collider_component.hpp>
#include <rigibody2d_component.hpp>
#include <world_controller.hpp>
#include <elevator_controller.hpp>
#include <ballsholder_controller.hpp>
#include <camera_controller.hpp>
#include <llave.hpp>
#include <puerta.hpp>
#include <puente.hpp>
#include <transform_task.hpp>

#undef main

using namespace engine;
using namespace glt;
using namespace rapidxml;





int main(int, char**)
{
    //Create a window
    Window window("engine", 800, 600);
    window.enable_vsync();

    //Create all different tasks
    //*********** TASKS
	std::unique_ptr < Transform_Task > transform_task(new Transform_Task(15));
    std::unique_ptr < Render		 > render(new Render(30, &window));
    std::unique_ptr < Read_input	 > read_input(new Read_input(10, &window));
    std::unique_ptr < Update		 > update(new Update(20));
    //***********

    //Initialice kernel
    Kernel::instance().initialization();

    //Create a scene
    Scene main_scene("main_scene", "assets/xml/sample-scene.xml", window);

    //Load Scene and run it
    Scene_manager::instance().run_scene(&main_scene);

    //We add to the player the different controllers

	Entity* catapulta = main_scene.get_entity("catapulta");
	std::unique_ptr < Payer_Movement_Controller > catapulta_controller = std::make_unique<Payer_Movement_Controller>(catapulta);
	main_scene.control_system->add_controller(catapulta_controller.get());

	Entity* llave = main_scene.get_entity("llave");
	std::unique_ptr < Llave_Controller > llave_controller = std::make_unique<Llave_Controller>(llave);
	main_scene.control_system->add_controller(llave_controller.get());

	Entity* puerta = main_scene.get_entity("puerta");
	std::unique_ptr < Puerta_Controller > puerta_controller = std::make_unique<Puerta_Controller>(puerta);
	main_scene.control_system->add_controller(puerta_controller.get());

	Entity* puente = main_scene.get_entity("puente");
	std::unique_ptr < Puente_Controller > puente_controller = std::make_unique<Puente_Controller>(puente);
	main_scene.control_system->add_controller(puente_controller.get());

    Kernel::instance().execute();

    return 0;
}