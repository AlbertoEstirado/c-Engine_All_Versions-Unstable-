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

#include <entity.hpp>
#include <transform.hpp>
#include <scene.hpp>

namespace engine
{
	Entity::Entity()
	{
		id = "";
	}

	Entity::Entity(std::string& id, Scene * scene)
	{
		this->scene = scene;
		this->id = id;
	}

	Entity::Entity(std::string & id, Transform* transform)
	{
		this->id = id;

		this->transform = transform;
		add_component(transform);
	}

	Entity::Entity(std::string & id)
	{
		this->id = id;

		this->transform = nullptr;
	}

	void Entity::add_component(Component * new_component)
	{
		components.push_back(new_component);
	}

	void Entity::add_transform(Transform* new_component)
	{
		transform = new_component;
	}

	Transform * Entity::get_transform()
	{
		return this->transform;
	}

}
