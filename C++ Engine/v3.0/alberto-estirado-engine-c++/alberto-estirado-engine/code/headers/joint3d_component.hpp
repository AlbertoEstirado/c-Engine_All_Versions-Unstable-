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
#include <physics3d_system.hpp>

namespace engine {

	class Joint3d_Component : public Component {
		~Joint3d_Component() = default;

	public:

		std::shared_ptr< btHingeConstraint > constraint;   //< Referencia a btConstraint

		Joint3d_Component(Entity* e, Physics3d_System& physics3d_system, Rigidbody3d_Component* other, btVector3 other_axis);
	};


}