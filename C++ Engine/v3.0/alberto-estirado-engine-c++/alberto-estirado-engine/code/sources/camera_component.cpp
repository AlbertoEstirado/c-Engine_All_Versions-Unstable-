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

#include <camera_component.hpp>
#include <iostream>
#include <entity.hpp>
#include <transform.hpp>

using namespace glt;
using namespace std;

namespace engine
{

	Camera_Component::Camera_Component(Entity* e, Renderer_System& render_system)
	{
		entity = e;

		camera.reset(new Camera(20.f, 1.f, 50.f, 1.f));

		//Add the camera to the render node of the system
		render_system.render_node->add(entity->id, camera);
		
		//Add the camera to ther render system
		render_system.add_render_component(this);
	}


}
