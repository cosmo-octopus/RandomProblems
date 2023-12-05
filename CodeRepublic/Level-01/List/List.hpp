#ifndef __LIST_HPP__
# define __LIST_HPP__

# include "List.h"

template <typename T>
List<T>::List(void): head(nullptr), tail(nullptr), size(0){}

template <typename T>
List<T>::~List()
{
	Node	*ptr;

	while (this->head)
	{
		ptr = this->head;
		this->head = this->head->next;
		delete ptr;
	}
	this->tail = nullptr;
	this->size = 0;
}

template <typename T>
void	List<T>::push_back(const T &data)
{
    Node *node = new Node(data);

    if (!this->head)
	{
        this->head = node;
		this->tail = node;
	}
	else
	{
        this->tail->next = node;
        this->tail = node;
    }
    this->size++;
}

template <typename T>
void	List<T>::list_print(void)
{
	Node	*tmp = this->head;

	if (!this->head)
		throw std::out_of_range("List is empty");
	std::cout << "( ";
	while (tmp)
	{
		std::cout << "[ " << tmp->data << " ] ";
		tmp = tmp->next;
	}
	std::cout << ")" << std::endl;
}

template <typename T>
void	List<T>::clear(void)
{
	Node	*ptr;

	while (this->head)
	{
		ptr = this->head;
		this->head = this->head->next;
		delete ptr;
	}
	this->tail = nullptr;
	this->size = 0;
}

template <typename T>
size_t	List<T>::get_size(void)
{
	return (this->size);
}

template <typename T>
void	List<T>::push_front(const T &data)
{
	Node	*node = new Node(data);

	node->next = this->head;
	this->head = node;
	this->size ++;
}

template <typename T>
void	List<T>::intert(size_t pos, const T &data)
{
	Node	*node;
	Node	*tmp;

	if (pos > this->size)
		throw std::out_of_range("Invalid position for insertion");
	if (pos == this->size - 1)
		push_back(data);
	else if (pos == 0)
		push_front(data);
	else
	{
		node = new Node(data);
		tmp = head;
		for (size_t i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		node->next = tmp->next;
		tmp->next = node;
		this->size ++;
	}
}

template <typename T>
void	List<T>::erase(size_t pos)
{
	Node	*tmp = head;
	Node	*del;

	if(pos > this->size)
		throw std::out_of_range("Invalid position to erase a node");
	if (pos == 0)
	{
        this->head = tmp->next;
        del = tmp;
    }
	else
	{
        for (size_t i = 0; i < pos - 1; i++)
            tmp = tmp->next;
        del = tmp->next;
        tmp->next = tmp->next->next;
    }

    delete del;
    this->size --;
}

#endif