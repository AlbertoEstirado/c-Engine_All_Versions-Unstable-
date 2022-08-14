/**
*
* @author Alberto Estirado López
*
* @date 26/01/2022
*
*/

#pragma once

#include <system.hpp>
#include <window.hpp>
#include <Render_Node.hpp>
#include <memory>



namespace engine
{

	class Input_System : public System
	{
	public:

		Input_System() = default;

		void run(float) override;

		~Input_System();

	};

}
