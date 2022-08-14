/**
*
* @author Alberto Estirado L�pez
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/

#include <iostream>
#include <engine/mesh_component.hpp>
#include <engine/entity.hpp>
#include <engine/transform.hpp>

using namespace glt;
using namespace std;

namespace engine
{
	Mesh_Component::Mesh_Component(Entity* e, const std::string& path, Renderer_System& render_system)
	{
		entity = e;

		model.reset(new Model_Obj(path));

		//Add the mesh to the render system
		render_system.render_node->add(entity->id, model);
		render_system.add_render_component(this);
	}

	Mesh_Component::Mesh_Component(Entity* e)
	{
		entity = e;
	}

}
