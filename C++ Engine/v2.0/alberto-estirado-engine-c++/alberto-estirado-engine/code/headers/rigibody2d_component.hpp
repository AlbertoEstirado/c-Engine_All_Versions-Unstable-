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

namespace engine {

	class Rigibody2d_Component : public Component {
		~Rigibody2d_Component() = default;

	public:

		struct Circle
		{
			float radius;
		};

		struct Box
		{
			float width;
			float height;
		};

		b2Body* body = nullptr;

		Rigibody2d_Component(Entity* e, Physics2d_System & physics2d_system, bool isStatic, bool isSensor);
		Rigibody2d_Component(Entity* e, Physics2d_System& physics2d_system, bool isStatic, bool isSensor, const Circle& circle);
		Rigibody2d_Component(Entity* e, Physics2d_System& physics2d_system, bool isStatic, bool isSensor, const Box & box);

	};


}