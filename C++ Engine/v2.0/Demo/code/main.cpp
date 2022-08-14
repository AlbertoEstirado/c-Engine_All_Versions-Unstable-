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

#undef main

using namespace engine;
using namespace glt;

Rigibody2d_Component::Rigibody2d_Component(Entity* e, Physics2d_System& physics2d_system, bool isStatic, bool isSensor) {

	b2BodyDef bodyDef;

	entity = e;
	if (isStatic) {
		bodyDef.type = b2_staticBody;
	}
	else {
		bodyDef.type = b2_dynamicBody;
	}

	bodyDef.position.Set(
		entity->get_transform()->get_position_x(),
		entity->get_transform()->get_position_y()
	);
	
	body = physics2d_system.physics_world.CreateBody(&bodyDef);
	physics2d_system.add_component(this);
}

Rigibody2d_Component::Rigibody2d_Component(Entity* e, Physics2d_System& physics2d_system, bool isStatic, bool isSensor, const Circle & cirlce)
	: Rigibody2d_Component(e, physics2d_system, isStatic, isSensor)
{

	b2CircleShape body_shape;
	body_shape.m_radius = cirlce.radius;

	//b2FixtureDef body_fixture;
	//
	//body_fixture.shape = &body_shape;
	//body_fixture.density = 0.10f;
	//body_fixture.restitution = 0.75f;
	//body_fixture.friction = 1.f;
	//body_fixture.isSensor = isSensor;

	body->CreateFixture(&body_shape, 1.f);

	body->GetFixtureList()->SetSensor(isSensor);
	body->GetFixtureList()->SetFriction(1.f);

}

Rigibody2d_Component::Rigibody2d_Component(Entity* e, Physics2d_System& physics2d_system, bool isStatic, bool isSensor, const Box & box)
{
	b2BodyDef bodyDef;

	entity = e;
	if (isStatic) {
		bodyDef.type = b2_staticBody;
	}
	else {
		bodyDef.type = b2_dynamicBody;
	}

	bodyDef.position.Set(
		entity->get_transform()->get_position_x(),
		entity->get_transform()->get_position_y()
	);

	body = physics2d_system.physics_world.CreateBody(&bodyDef);
	physics2d_system.add_component(this);

	b2PolygonShape body_shape;
	
	body_shape.SetAsBox(box.width, box.height);

	body->CreateFixture(&body_shape, 1.f);
	body->GetFixtureList()->SetSensor(isSensor);
}

int main(int, char**)
{
    //Create a window
    Window window("engine", 800, 600);
    window.enable_vsync();

    //Create all different tasks
    //*********** TASKS
    std::unique_ptr < Render     > render(new Render(30, &window));
    std::unique_ptr < Read_input > read_input(new Read_input(10, &window));
    std::unique_ptr < Update     > update(new Update(20));
    //***********

    //Initialice kernel
    Kernel::instance().initialization();

    //Create a scene
    Scene main_scene("main_scene", "../../assets/xml/sample-scene.xml", window);

    //Load Scene and run it
    Scene_manager::instance().run_scene(&main_scene);

    //We add to the player the different controllers
    Entity* motor = main_scene.get_entity("ruedaDetras");
	std::unique_ptr < Payer_Movement_Controller > p_m = std::make_unique<Payer_Movement_Controller>(motor);
    main_scene.control_system->add_controller(p_m.get());
	std::unique_ptr < World_Controller > w_c = std::make_unique<World_Controller>(motor);
	main_scene.control_system->add_controller(w_c.get());

	Entity* plataforma = main_scene.get_entity("plataforma");
	std::unique_ptr < Elevator_Controller > elevator_c = std::make_unique<Elevator_Controller>(plataforma);
	main_scene.control_system->add_controller(elevator_c.get());

	Entity* holder = main_scene.get_entity("sujetapelotas");
	std::unique_ptr < Ballsholder_Controller > holder_c = std::make_unique<Ballsholder_Controller>(holder);
	main_scene.control_system->add_controller(holder_c.get());

    Kernel::instance().execute();

    return 0;
}