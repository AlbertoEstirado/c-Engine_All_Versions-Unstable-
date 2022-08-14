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

#include <keyboardcontrol_component.hpp>
#include <entity.hpp>
#include <scene.hpp>
#include <transform.hpp>

namespace engine
{

	Keyboardcontrol_Component::Keyboardcontrol_Component(Entity* e)
	{
		entity = e;

		entity->scene->get_dispatcher().add_listener("w", *this);
		entity->scene->get_dispatcher().add_listener("a", *this);
		entity->scene->get_dispatcher().add_listener("s", *this);
		entity->scene->get_dispatcher().add_listener("d", *this);
	}

	void Keyboardcontrol_Component::receptor(Message& message)
	{
		if (message.get_Id() == "w")
		{
			entity->get_transform()->position.z -= 0.1f;
		}
		if (message.get_Id() == "a")
		{
			entity->get_transform()->position.x -= 0.1f;
		}
		if (message.get_Id() == "s")
		{
			entity->get_transform()->position.z += 0.1f;
		}
		if (message.get_Id() == "d")
		{
			entity->get_transform()->position.x += 0.1f;
		}
	}
}
