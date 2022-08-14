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

#include <light_component.hpp>
#include <iostream>
#include <entity.hpp>
#include <transform.hpp>


using namespace glt;
using namespace std;

namespace engine
{
	Light_Component::Light_Component(Entity * e, Renderer_System & render_system)
	{ 
		entity = e;

		light.reset( new Light);
	
		render_system.render_node->add(entity->id , light);
		
		render_system.add_render_component(this);
	}
	
	

}
