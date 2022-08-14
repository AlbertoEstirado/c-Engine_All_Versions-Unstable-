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

#include <system.hpp>
#include <entity.hpp>


namespace engine
{

	void System::run(float time = 0)
	{
		
	}

	void System::add_component(Component * new_component)
	{
		components.push_back(new_component);
	}

}
