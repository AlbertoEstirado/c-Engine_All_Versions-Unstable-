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

#include <physics3d_system.hpp>
#include <rigidbody3d_component.hpp>
#include <entity.hpp>
#include <transform.hpp>

namespace engine 
{
	Physics3d_System::Physics3d_System() : collisionDispatcher(&collisionConfiguration)
	{
		dynamicsWorld.reset(new btDiscreteDynamicsWorld(
			&collisionDispatcher,
			&overlappingPairCache,
			&constraintSolver,
			&collisionConfiguration
		));

		dynamicsWorld->setGravity(btVector3(0, -10, 0));
	}


	void Physics3d_System::run(float delta)
	{
		dynamicsWorld->stepSimulation(delta);

		for (auto& component : components)
		{
			Rigidbody3d_Component* physics_component = dynamic_cast<Rigidbody3d_Component*>(component);
			btTransform physics_transform;
			physics_component->body->getMotionState()->getWorldTransform(physics_transform);
			//physics_component->body->getMotionState()->

			
			glm::mat4 graphics_transform;
			physics_transform.getOpenGLMatrix(glm::value_ptr(graphics_transform));
			btVector3 m = physics_transform.getOrigin(); 

			//Aplicamos la escala del transform a la matriz de fisicas
			graphics_transform = glm::scale(graphics_transform, glm::vec3(
				component->entity->transform->scale.x, 
				component->entity->transform->scale.y, 
				component->entity->transform->scale.z)
			);

			component->entity->transform->matrix = graphics_transform;

		}

	}
}