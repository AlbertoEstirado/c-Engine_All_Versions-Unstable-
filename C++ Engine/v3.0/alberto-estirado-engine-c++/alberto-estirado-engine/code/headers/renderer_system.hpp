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

#ifndef RENDERER_SYSTEM
#define RENDERER_SYSTEM

#pragma once

#include <system.hpp>
#include <window.hpp>
#include <Render_Node.hpp>
#include <memory>



namespace engine
{
	class Render_Component;

	class Renderer_System : public System
	{

		Window* window;											//< Reference of the curren window
		
	public:

		std::vector<Render_Component*> render_components;		//< List of all render component to process

		std::unique_ptr < glt::Render_Node > render_node;		//< Render node that process all components

		Renderer_System(Window& window);

		void run(float) override;
		
		/*
		* Add a render component to the list
		* @param Render_Component
		*/
		void add_render_component(Render_Component*);

		~Renderer_System();


	};

}

#endif
