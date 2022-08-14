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

#include <kernel.hpp>


namespace engine
{
	Kernel::Kernel()
	{
		running = true;
	}

	void Kernel::initialization()
	{
		//Initialize all task in order
        for (auto task : tasks)
        {
            task->initialize();
        }
	}

	void Kernel::execute()
	{
		//While kernel is running
		do 
		{
			//Run all task in order
			for (auto task : tasks)
			{
				task->run(0);
			}
		} while (running);

		end();
	}

	void Kernel::end()
	{
		//End all task in order
		for (auto task : tasks)
		{
			task->end();
		}
	}

	void Kernel::add_task(Task * new_task)
	{
		// We add the task and order it based on its priority 
		tasks.insert(new_task);
	}

	void Kernel::stop_kernel()
	{
		running = false;
	}
	
}
