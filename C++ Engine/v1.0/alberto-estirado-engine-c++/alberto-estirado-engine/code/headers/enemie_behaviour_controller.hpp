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

#include <controller.hpp>
#include <glm/glm.hpp>


namespace engine
{
	class Entity;
	
	typedef glm::vec3 Vector3;
	
	class Enemie_Behaviour_Controller : public Controller//, public Dispatcher::Listener
	{
	public:
	
		float speed;
		Vector3 dir;
	
		Enemie_Behaviour_Controller(Entity* e);
	
		void update() override;
		//void receptor(Message& message) override;
	
	};

}
