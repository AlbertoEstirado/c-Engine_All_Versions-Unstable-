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

#ifndef TASK
#define TASK

#pragma once

#include <iostream>

namespace engine
{
	class Task
	{

	public:

		int priority;			//< The order of execution in the kernel is based on this value.

		struct Compare
		{
			/*
			* Operator to be able to order based on a priority, it is necessary if we use a map of pointers
			* @param a
			* @param b
			*/
			bool operator () (const Task * a, const Task * b) const
			{
				return  a->priority < b->priority;
			}
		};


		Task(int priority = 0)
		{
			this->priority = priority;
		}

		virtual void run(float time) = 0;
		virtual void initialize() = 0;
		virtual void end() = 0;

		/*
		* Operator to be able to order based on a priority
		* @param other
		*/
		bool operator < (const Task& other) const
		{
			return this->priority < other.priority;
		}

		virtual ~Task()= default;

	};

}

#endif // !TASK
