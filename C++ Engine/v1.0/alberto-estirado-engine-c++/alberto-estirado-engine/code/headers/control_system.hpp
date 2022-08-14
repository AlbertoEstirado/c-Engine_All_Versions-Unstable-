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

#include <system.hpp>
#include <vector>

namespace engine
{
	class Controller;

	class Control_System: public System
	{
	public:

		std::vector<Controller*> controllers;		//< List of all controllers

		Control_System() {};
		
		/*
		* Will run all controllers of the list
		* @param float
		*/
		void run(float) override;	
		
		/*
		* Add a new controller to the list
		* @param Controller
		*/		
		void add_controller(Controller*);

		~Control_System();
	
	};

}
