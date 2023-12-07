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
		void	push_front(const T &data);
		void	list_print(void);
		void	clear(void);
		size_t	get_size(void);
		void	intert(size_t pos, const T &data);
		void	erase(size_t pos);
		void	pop_back(void);
		void	pop_front(void);
		bool	empty(void);
		void	unique(void);
		List<T>	&merge(List<T> &list);

		List<T>	&operator= (const List &list);
		Node* merge(Node* first, Node* second);
    	Node* mergeSort(Node* head);
		void sortList(List<T>& list);

};

# include "List.hpp"

#endif