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
#pragma once

#include <entity.hpp>
#include <component.hpp>
#include <box2d/box2d.h>

namespace engine
{
	class Contact_Listener_Component : public b2ContactListener
	{
	public:

		virtual void BeginContact(b2Contact* contact) { B2_NOT_USED(contact); }
		virtual void EndContact(b2Contact* contact) { B2_NOT_USED(contact); }

	};

}