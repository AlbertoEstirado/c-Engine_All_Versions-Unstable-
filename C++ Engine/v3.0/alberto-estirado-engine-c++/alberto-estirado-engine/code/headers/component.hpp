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

#ifndef COMPONENT
#define COMPONENT

#pragma once

namespace engine
{
	class Entity;

	class Component
	{
	protected:
	public:

		Entity* entity = nullptr;
		virtual ~Component() = default;
	};

}

#endif
