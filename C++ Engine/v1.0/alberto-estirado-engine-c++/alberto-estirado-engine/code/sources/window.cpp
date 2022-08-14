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

#include <iostream>

#include <window.hpp>
#include <cassert>
#include <OpenGL.hpp>
#include <SDL.h>
#include <kernel.hpp>
#include <keyboard.hpp>
#include <scene_manager.hpp>
#include <scene.hpp>

namespace engine
{
	Window::Window(const std::string& title, size_t width, size_t height, bool fullscreen)
	{
		exit = false;
		gl_context = nullptr;

		this->width = width;
		this->height = height;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			SDL_Log("Error SDL2.");
		}
		else
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		}

		if (not window)
		{
			SDL_Log("Error window.");
		}
		else
		{
			surface = SDL_GetWindowSurface(window);
			gl_context = SDL_GL_CreateContext(window);

			assert(gl_context != nullptr);

			if(gl_context && glt::initialize_opengl_extensions())
			{
				if (fullscreen)
				{
					SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
				}
			}
		}
	}

	void Window::end()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Window::handle_events()
	{
		SDL_Event event;

		//Get the event from sdl
		while (SDL_PollEvent(&event) > 0)
		{
			if (event.type == SDL_QUIT)
			{
				exit = true;
				Kernel::instance().stop_kernel();
			}

			//We send a message to the scene dispatcher
			if(event.type == SDL_KEYDOWN)
			{
				//Create the message
				Message* new_input_message = new Message(Keyboard::instance().sdlk_to_string(event.key.keysym.sym) + "_keydown");
				Scene_manager::instance().current_scene->dispatcher->multicast(*new_input_message);
			}
			if (event.type == SDL_KEYUP)
			{
				//Create the message
				Message* new_input_message = new Message(Keyboard::instance().sdlk_to_string(event.key.keysym.sym) + "_keyup");
				Scene_manager::instance().current_scene->dispatcher->multicast(*new_input_message);
			}
		}
	}

	void Window::enable_vsync()
	{
		if (gl_context) SDL_GL_SetSwapInterval(1);
	}

	void Window::disable_vsync()
	{
		if (gl_context) SDL_GL_SetSwapInterval(0);
	}

	void Window::clear() const
	{
		if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::swap_buffers() const
	{
		if (gl_context) SDL_GL_SwapWindow(window);
	}

	unsigned Window::get_width() const
	{
		int width = 0, height;

		if (window) SDL_GetWindowSize(window, &width, &height);

		return unsigned(width);
	}

	unsigned Window::get_height() const
	{
		int width, height = 0;

		if (window) SDL_GetWindowSize(window, &width, &height);

		return unsigned(height);
	}

}
