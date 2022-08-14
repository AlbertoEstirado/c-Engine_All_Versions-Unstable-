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

#ifndef KERNEL
#define KERNEL

#pragma once

#include <set>

#include "window.hpp"
#include "task.hpp"

#include <iostream>


namespace engine
{
	class Render;

	class Kernel
	{

	public:

		static Kernel& instance()				//< Singletone
		{
			static Kernel kernel;
			return kernel;
		}

		std::set<Task*, Task::Compare> tasks;   //< Reference to all tasks ordered based on their priority

		bool running = true;

		Kernel();

		/**
		* @brief Initialization of all tasks
		*/
		void initialization();

		/**
		* @brief Run all tasks
		*/
		void execute();

		/**
		* @brief End of all tasks
		*/
		void end();

		/**
		* @brief Change running to false
		*/
		void stop_kernel();

		/**
		* @brief Add a new task to kernel
		* @param Task
		*/
		void add_task(Task*);

	};

	
}

#endif
