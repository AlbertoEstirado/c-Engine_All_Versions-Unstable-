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

#include <LevelEditor/API.hpp>
#include <LevelEditor/scene.hpp>
#include <LevelEditor/editor.hpp>
#include <LevelEditor/camera_component.hpp>
#include <LevelEditor/light_component.hpp>
#include <LevelEditor/mesh_component.hpp>

#include <fstream>
#include <sstream>
#include <iostream>
#include <list>

#include <rapidxml.hpp>
#include <rapidxml_print.hpp>

using namespace rapidxml;

namespace level_editor
{

	class Serializer
	{
		std::list<std::string> strings;			//< Lista para guardar informacion de datos.
		std::list<xml_node<>* > nodes;

	public:

		xml_document<> doc;						//< Documento xml.

		/// <summary>
		/// Guarda y retorna el puntero a un string para que no se pierda la referencia.
		/// (rapidxml necesita que los punteros persistan)
		/// </summary>
		/// <param name="string"></param>
		/// <returns></returns>
		API const char* save_string(const std::string& string);

		/// <summary>
		/// Guarda la escena a un xml.
		/// </summary>
		/// <param name="scene"></param>
		/// <returns></returns>
		API void save_scene(level_editor::Scene scene);

		/// <summary>
		/// Parsea el transform al formato xml del motor.
		/// </summary>
		/// <param name="t"></param>
		/// <returns></returns>
		xml_node<>* save_transform(level_editor::Transform* t);

		/// <summary>
		/// Parsea la light al formato xml del motor.
		/// </summary>
		/// <returns></returns>
		xml_node<>* save_light();

		/// <summary>
		/// Parsea el mesh al formato xml del motor.
		/// </summary>
		/// <param name="c"></param>
		/// <returns></returns>
		xml_node<>* save_mesh(level_editor::Mesh_Component * c);

		/// <summary>
		/// Parsea la camara al formato xml del motor.
		/// </summary>
		/// <returns></returns>
		xml_node<>* save_camera();

		/// <summary>
		/// Recorre todos los componetes de la entidad y los parsea al formato xml del motor.
		/// </summary>
		/// <param name="entities"></param>
		/// <param name="e"></param>
		/// <returns></returns>
		API xml_node<>* save_entity(xml_node<>* entities, Entity * e);
	
	};

}
