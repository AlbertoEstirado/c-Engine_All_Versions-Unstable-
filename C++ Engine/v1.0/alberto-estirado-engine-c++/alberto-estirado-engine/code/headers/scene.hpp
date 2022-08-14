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

#include <iostream>
#include <map>

#include "entity.hpp"
#include "scene_manager.hpp"
#include <rapidxml.hpp>
#include <dispatcher.hpp>
#include <render_component.hpp>
#include <control_system.hpp>
#include <collision_system.hpp>
#include <memory>

#pragma once

namespace engine
{
	class Window;

	typedef std::string Id;

	class Scene
	{
		enum STATE											//< Enum of the possible states of the scene
		{
			UNINITIALIZED,
			LOADING,
			ONGOIN,
			WAITTING,
			FINISHED,
		};

		STATE state;										//< State of the scene

		std::map<Id, Entity * > entities;					//< List of all the entities that belong to the scene, each entity has an Id to identify them
		
	public:

		std::unique_ptr <Dispatcher>		 dispatcher;			//< Menssage system
		std::unique_ptr <Renderer_System>	 renderer_system;		//< Pointer of the render system 
		std::unique_ptr <Control_System>	 control_system;		//< Pointer of the control system
		std::unique_ptr <Collision_System>	 collision_system;		//< Pointor of the colision system
		
		std::string name;									//< Name of the scene
		std::string path;									//< Path where the xml file persist
	
		/**
		* @brief Constructor of the scene, we initialize all systems and save the path
		* @param name
		* @param path
		* @param window
		*/
		Scene(const std::string & name, const std::string & path , Window & window);

		/**
		* @brief Funtion that parse the xml and creates entities and their componensts
		*/
		void load_scene();

		/**
		* @brief Runs the awake method of all systems
		*/
		void awake();

		/**
		* @brief Runs the start method of all systems
		*/
		void start();

		/**
		* @brief Runs the run method of all systems
		* @param time
		*/
		void update(float time);

		/**
		* @brief Runs the Render System
		*/
		void render();

		/**
		* @brief We add to the map a new entity
		* @param Entity
		*/
		void add_entity(Entity*);

		/**
		* @brief Getter of the dispatcher
		*/
		Dispatcher& get_dispatcher();

		/**
		* @brief Returns the entity with the same id
		* @param id
		*/
		Entity * get_entity(const std::string &);

		/**
		* @brief It will read the xml and change all the transforms to their initial values
		*/
		void reset_transforms();

		/**
		* @brief Parse xml node to a transform component, and it will be added to the entity
		* @param xml_node
		* @param entity
		*/
		void parse_transform(rapidxml::xml_node<>*, Entity*);

		/**
		* @brief Parse xml node to a collider component, and it will be added to the entity
		* @param xml_node
		* @param entity
		*/
		void parse_box_collider_component(rapidxml::xml_node<>*, Entity*);

		/**
		* @brief Parse xml node to a component, and it will be added to the entity (some components use their own function)
		* @param xml_node
		* @param entity
		*/
		void parse_node_component(rapidxml::xml_node<>*, Entity*);

		std::string get_name ()
		{
			return name;
		}
	
	};


}
