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

#include <map>
#include <string>
#include <variant.hpp>

namespace engine
{
	class Message
	{

	private:
		std::string id;
		std::map<std::string, Variant> parameters;

	public:

		Message(const std::string& id) : id(id){}

		/**
		 * @brief Get a parameter from the message
		 * @param id 
		 */
		Variant get_Variant(const std::string id)
		{
			return parameters[id];
		}

		/**
		 * @brief Get id
		 */
		std::string get_Id()
		{
			return id;
		}

		/**
		 * @brief Add a parameter to the message
		 * @param id
		 * @param value
		 */
		void add_Parameter(const std::string& id, const Variant& value)
		{
			parameters[id] = value;
		}

		Variant& operator[](const std::string id)
		{
			return parameters[id];
		}

		operator std::string() const
		{
			return id;
		}
	};
}
