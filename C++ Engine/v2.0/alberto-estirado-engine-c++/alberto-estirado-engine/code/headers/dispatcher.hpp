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
#include <Message.hpp>

namespace engine
{

	class Dispatcher
	{
	public:

		/**
		 * Struct to hear messages
		 */
		struct Listener
		{
			virtual ~Listener() = default;
			virtual void receptor(Message& message) = 0;
		};

	private:

		std::map < std::string, Listener*> listeners_;


	public:

		/**
		 * Add a listener
		 * @param id 
		 * @param listener
		 */
		void add_listener(std::string id, Listener& listener)
		{
			listeners_.insert(std::pair<std::string, Listener*>(id, &listener));
		}

		/**
		 * Remove a listener
		 * @param listener
		 */
		void remove_listener(Listener& listener)
		{
			for (auto begin = listeners_.begin(), end = listeners_.end(); begin != end; ++begin)
			{
				if (begin->second == &listener)
				{
					listeners_.erase(begin);
					return;
				}
			}
		}

		/**
		 * Broadcast a message
		 * @param message 
		 */
		void multicast(Message& message)
		{
			if (listeners_.count(message))
			{
				for (auto& listener : listeners_)
				{
					listener.second->receptor(message);
				}
			}
		}

	};

}
