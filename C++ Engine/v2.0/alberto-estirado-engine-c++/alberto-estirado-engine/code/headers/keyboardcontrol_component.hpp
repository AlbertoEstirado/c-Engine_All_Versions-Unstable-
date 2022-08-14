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

#include <component.hpp>
#include <dispatcher.hpp>

namespace engine
{
	
	class Keyboardcontrol_Component : public Component, public Dispatcher::Listener
	{

		~Keyboardcontrol_Component() = default;

	public:

		Keyboardcontrol_Component(Entity* e);

		void receptor(Message& message) override;
	};

}
