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
	Node	*node = new Node(data);
	Node	*tmp = this->head;

	while (tmp)
		tmp = tmp;
	tmp = node;
	if (!this->head)
		this->head = node;
	this->tail = node;
	this->size ++;
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

#endif