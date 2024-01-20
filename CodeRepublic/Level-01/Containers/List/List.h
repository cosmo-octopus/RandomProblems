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

		/* iterators */
		class Iterator
		{
			public:
				Node	*current;

				Iterator(Node *node) : current(node) {}

				T	&operator*() const
				{
					return (current->data);
				}

				Iterator	&operator++()
				{
					current = current->next;
					return (*this);
				}

				Iterator	operator++(int)
				{
					Iterator temp = *this;
					++(*this);
					return (temp);
				}

				bool operator==(const Iterator& other) const
				{
					return (current == other.current);
				}

				bool operator!=(const Iterator& other) const
				{
					return (!(*this == other));
				}
		};

		class ReverseIterator
		{
			public:
				Node	*current;
				Node	*head;

				ReverseIterator(Node* node, Node* head) : current(node), head(head) {}

				T	&operator*() const
				{
					return current->data;
				}

				ReverseIterator	&operator++()
				{
					if (current == nullptr)
						return *this;

					Node* temp = head;
					while (temp != nullptr && temp->next != current)
						temp = temp->next;

					if (temp != nullptr)
						current = temp;
					else
						current = nullptr;

					return (*this);
				}

				ReverseIterator	operator++(int)
				{
					ReverseIterator	temp = *this;
					++(*this);
					return (temp);
				}

				bool operator==(const ReverseIterator& other) const
				{
					return (current == other.current);
				}

				bool operator!=(const ReverseIterator& other) const
				{
					return !(*this == other);
				}
		};

	private:
		Node	*head;
		Node	*tail;
		size_t	size;
	
	/*  methods  */
	public:
		List(void);
		~List();
		List(const List& other) : head(nullptr), tail(nullptr), size(0)
		{
			Node* temp = other.head;
			while (temp != nullptr)
			{
				push_back(temp->data);
				temp = temp->next;
			}
		}

		void	push_back(const T &data);
		void	push_front(const T &data);
		void	list_print(void);
		void	clear(void);
		size_t	get_size(void) const;
		void	intert(size_t pos, const T &data);
		void	erase(size_t pos);
		void	pop_back(void);
		void	pop_front(void);
		bool	empty(void);
		void	unique(void);
		List<T>	&merge(List<T> &list);
		void	sort(void);
		void	reverse(void);
		void	swap(List<T> &other);

		/* iterators */
		Iterator begin()
		{
        	return Iterator(head);
    	}

		Iterator end()
		{
			return Iterator(nullptr);
		}

		ReverseIterator rbegin()
		{
			return ReverseIterator(tail, head);
		}

		ReverseIterator rend()
		{
			return ReverseIterator(nullptr, head);
		}

		const Iterator cbegin() const
		{
			return Iterator(head);
		}

		const Iterator cend() const
		{
			return Iterator(nullptr);
		}

		const ReverseIterator crbegin() const
		{
			return ReverseIterator(tail, head);
		}

		const ReverseIterator crend() const
		{
			return ReverseIterator(nullptr, head);
		};

		/*  operators  */
		List<T>	&operator= (const List &list);

		template <typename U>
    	friend bool operator==(const List<U>& lhs, const List<U>& rhs);

    	template <typename U>
    	friend bool operator!=(const List<U>& lhs, const List<U>& rhs);

    	template <typename U>
    	friend bool operator<(const List<U>& lhs, const List<U>& rhs);

    	template <typename U>
    	friend bool operator<=(const List<U>& lhs, const List<U>& rhs);

    	template <typename U>
    	friend bool operator>(const List<U>& lhs, const List<U>& rhs);

    	template <typename U>
    	friend bool operator>=(const List<U>& lhs, const List<U>& rhs);

	private:
		Node	*mergeSort(Node* head);
    	Node	*getMiddle(Node* head);
    	Node	*merge(Node* left, Node* right);
};

# include "List.hpp"

#endif