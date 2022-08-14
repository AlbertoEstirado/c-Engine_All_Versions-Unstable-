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
#include <chrono>
#include <thread>


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
		const float target_fps = 60.f;                     
		const float target_time = 1.f / target_fps;
		float delta_time = target_time;

		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
			
		//While kernel is running
		do 
		{
			std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();


			//Run all task in order
			for (auto task : tasks)
			{
				task->run(delta_time);
			}

			//std::cout << delta_time << std::endl;

			std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);

			if (elapsed.count() < target_time)
			{
				double sleepTime = target_time - elapsed.count();
				std::this_thread::sleep_for(std::chrono::milliseconds(int(sleepTime * 1000)));
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
