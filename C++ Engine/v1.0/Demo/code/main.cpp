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

#undef main

using namespace engine;
using namespace glt;

int main(int, char**)
{
    //Create a window
    Window* window = new Window("engine", 800, 600);
    window->enable_vsync();

    //Create all different tasks
    //*********** TASKS
    std::unique_ptr < Render     > render(new Render(30, window));
    std::unique_ptr < Read_input > read_input(new Read_input(10, window));
    std::unique_ptr < Update     > update(new Update(20));
    //***********

    //Initialice kernel
    Kernel::instance().initialization();

    //Create a scene
    Scene* main_scene = new Scene("main_scene", "../../assets/xml/sample-scene.xml", *window);

    //Load Scene and run it
    Scene_manager::instance().run_scene(main_scene);

    //We add to the player the different controllers
    Entity* player = main_scene->get_entity("player");
    Payer_Movement_Controller* p_m = new Payer_Movement_Controller(player);
    main_scene->control_system->add_controller(p_m);

    //We add to the enemies the different controllers
    Entity* enemie1 = main_scene->get_entity("enemie1");
    Entity* enemie2 = main_scene->get_entity("enemie2");
    Entity* enemie3 = main_scene->get_entity("enemie3");
    Entity* enemie4 = main_scene->get_entity("enemie4");

    main_scene->control_system->add_controller(new Enemie_Behaviour_Controller(enemie1));
    main_scene->control_system->add_controller(new Enemie_Behaviour_Controller(enemie2));
    main_scene->control_system->add_controller(new Enemie_Behaviour_Controller(enemie3));
    main_scene->control_system->add_controller(new Enemie_Behaviour_Controller(enemie4));

    Kernel::instance().execute();

    return 0;
}