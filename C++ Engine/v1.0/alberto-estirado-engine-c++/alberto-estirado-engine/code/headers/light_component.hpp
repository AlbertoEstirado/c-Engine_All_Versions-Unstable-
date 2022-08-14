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
#include <Light.hpp>
#include <renderer_system.hpp>
#include <render_component.hpp>


namespace engine
{

	class Light_Component : public Render_Component
	{

		~Light_Component() = default;

	public:

		std::shared_ptr< glt::Light > light = nullptr;			//< Pointer to the light

		/**
		* @brief Set the refernce of the owner and a reference of the renderer system
		* @param entity
		* @param renderer system
		*/
		Light_Component(Entity* e, Renderer_System&);

		/**
		* @brief Returns the node that persist in the light
		*/
		glt::Node& get_node() override
		{
			return *light;
		}
	};
}

