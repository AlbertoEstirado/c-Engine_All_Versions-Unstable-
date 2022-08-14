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

#include <SDL.h>
#include <ciso646>
#include <iostream>

#pragma once

namespace engine
{
	class Window
	{

	public:

		bool exit;								//< Bool that close the window

		size_t width = 0;
		size_t height = 0;				

		SDL_Window	* window = nullptr;			//< Sld window
		SDL_Surface	* surface = nullptr;		//< Sdl surface
		
		SDL_GLContext gl_context;				//< OpenGl contex

		Window(const std::string& title, size_t  width, size_t height, bool fullscreen = false);
		
 		/**
         * @brief Function called before destroying the window
         */
		void end			();
		/**
         * @brief Function where we handle all input events
         */
		void handle_events	();

		void enable_vsync	();
		void disable_vsync	();
		void clear			() const;
		void swap_buffers	() const;

		unsigned get_width	() const;
		unsigned get_height	() const;
	};
}
