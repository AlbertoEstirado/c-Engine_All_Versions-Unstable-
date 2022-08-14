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

#include <control_system.hpp>
#include <controller.hpp>


namespace engine
{
	
	void Control_System::run(float t)
	{
		for (size_t i = 0; i < controllers.size(); i++)
		{
			controllers[i]->update();
		}
	}

	void Control_System::add_controller(Controller* new_controller)
	{
		controllers.push_back(new_controller);
	}

	Control_System::~Control_System()
	{
		
	}

	
}
