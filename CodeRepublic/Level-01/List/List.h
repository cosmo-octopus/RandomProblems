#ifndef __LIST_H__
# define __LIST_H__

# include <limits>
# include <utility>
# include <iostream>
# include <stdexcept>

template <typename T>
class	List
{
	public:
		/*  node  */
		class	Node
		{
			public:
				T		data;
				Node*	next;

				Node(void): data(0), next(nullptr){}
				Node(const T &data): data(data), next(nullptr){}
		};
	private:
		Node	*head;
		Node	*tail;
		size_t	size;
	
	public:
		List(void);
		~List();

		void	push_back(const T &data);
		void	list_print(void);
};

# include "List.hpp"

#endif