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

#include "task.hpp"
#include "kernel.hpp"

namespace engine
{

	class Render : public Task
	{

	public:

		Window* window;

		/*
		* It will create the task and it will be automatically added to the kernel
		* @param priority
		* @param window
		*/
		Render(int priority, Window * window) : Task(priority)
		{
			this->window = window;

			this->priority = priority;

			Kernel::instance().add_task(this);
		}

		void initialize();
		void run(float time);
		void end();

	};
}


