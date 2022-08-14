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

#include <component.hpp>
#include "box2d\box2d.h"
#include <physics2d_system.hpp>

namespace engine
{
	class Joint_Component : public Component {
		~Joint_Component() = default;

	public:

		b2RevoluteJoint* joint = nullptr;

		Joint_Component(Entity* e, Physics2d_System & physics2d_system, Rigibody2d_Component* body_a, Rigibody2d_Component* body_b, bool enable_motor = false);
	};


}