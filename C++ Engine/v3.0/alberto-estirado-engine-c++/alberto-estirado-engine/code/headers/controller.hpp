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

#ifndef CONTROLLER
#define CONTROLLER

#pragma once

#include "entity.hpp"

namespace engine
{
	class Controller 
	{

	public:

		Entity* entity = nullptr;

		/**
		* @brief Run behaviours of the entity
		*/
		virtual void update() = 0;
	};

}

#endif
