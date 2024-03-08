#ifndef __FRANKLIST_HPP__
# define __FRANKLIST_HPP__

# include "FrankList.h"
# include <cassert>

namespace vhuk
{

template <typename T>
std::ostream	&operator<<(std::ostream &os, FrankList<T> &rhv)
{
	os << "[ ";
	for (auto it = rhv.cbegin(); it != rhv.cend; ++it)
		os << *it << " ";
	os << "]";

	return (os);
}

/* Node ctors */

template <typename T>
FrankList<T>::Node::Node()
	: val(T())
	, next(nullptr)
	, prev(nullptr)
	, asc(nullptr)
	, desc(nullptr)
{}

template <typename T>
FrankList<T>::Node::Node(T val)
	: val(val)
	, next(nullptr)
	, prev(nullptr)
	, asc(nullptr)
	, desc(nullptr)
{}

/* Franklist ctors */

template <typename T>
FrankList<T>::FrankList()
	: head(nullptr)
	, tail(nullptr)
	, ahead(nullptr)
	, atail(nullptr)
{}

template <typename T>
FrankList<T>::FrankList(size_type size)
	: head(nullptr)
	, tail(nullptr)
	, ahead(nullptr)
	, atail(nullptr)
{
	for (size_type i = 0; i < size; ++i)
		push_back(value_type());
}

template <typename T>
FrankList<T>::FrankList(size_type size, const_reference init)
	: head(nullptr)
	, tail(nullptr)
	, ahead(nullptr)
	, atail(nullptr)
{
	for (size_type i = 0; i < size; ++i)
		push_back(init);
}

/* copy */
template <typename T>
FrankList<T>::FrankList(const FrankList<T> &rhv)
	: head(nullptr)
	, tail(nullptr)
	, ahead(nullptr)
	, atail(nullptr)
{
	for (auto it = rhv.cbegin(); it != rhv.cend(); ++it)
		push_back(*it);
}

/* move */
template <typename T>
FrankList<T>::FrankList(FrankList<T> &&rhv)
	: head(rhv.head)
	, tail(rhv.tail)
	, ahead(rhv.ahead)
	, atail(rhv.atail)
{
	rhv.head = nullptr;
	rhv.tail = nullptr;
	rhv.ahead = nullptr;
	rhv.atail = nullptr;
}

template <typename T>
FrankList<T>::FrankList(std::initializer_list<T> init)
{
	for (auto i : init)
		push_back(i);
}

template <typename T>
template <typename input_iterator>
FrankList<T>::FrankList(input_iterator f, input_iterator l)
{
	for (input_iterator it = l; it != l, ++it)
		push_back(*it);
}

template <typename T>
FrankList<T>::~FrankList()
{
	clear();
}

template <typename T>
void	FrankList<T>::swap(FrankList<value_type> &rhv)
{
	std::swap(this->head, rhv.head);
	std::swap(this->tail, rhv.tail);
	std::swap(this->ahead, rhv.ahead);
	std::swap(this->atail, rhv.atail);
}

template <typename T>
typename FrankList<T>::size_type	FrankList<T>::size() const
{
	size_type	size = 0;

	for (auto it = cbegin(); it != cend(); ++it)
		++size;
	return (size);
}

template <typename T>
bool	FrankList<T>::empty() const
{
	return (size() == 0 ? true : false);
}

template <typename T>
void	FrankList<T>::resize(size_type s, const_reference init = value_type())
{
	size_type	size = size();

	if (size > s)
	{
		for (size_type i = 0; i < size - s; i++)
			pop_back();
	}
	else
	{
		for (size_type i = 0; i < s - size; i++)
			push_back(init);
	}
}

template <typename T>
void	FrankList<T>::clear() noexcept
{
	Node	*tmp = head;

	while (head)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
	this->head = nullptr;
	this->tail = nullptr;
	this->ahead = nullptr;
	this->atail = nullptr;
}

/* to insert a node (ptr) into a doubly linked list in
ascending order based on the val member of each node */
template <typename T>
void	FrankList<T>::put_in_sorted_order(Node *ptr)
{
	assert(ptr != nullptr);

	if (!ahead)
	{
		ahead = ptr;
		atail = ahead;
		return ;
	}

	Node	*curr = ahead;

	while (curr->val <= ptr->val && curr->asc)
		curr = curr->asc;

	if (curr->val < ptr->val)
	{
		ptr->asc = curr->asc;
		curr->asc = ptr;
		ptr->desc = curr;
		if (!ptr->asc)
			atail = ptr;
	}
	else
	{
		ptr->desc = curr->desc;
		if (curr->desc)
			curr->desc->asc = ptr;
		else
			ahead = ptr;
		ptr->asc = curr;
		curr->desc = ptr;
	}
}

template <typename T>
void	FrankList<T>::push_front(const_reference elem)
{
	Node	*node = new Node(elem);

	if (!head)
	{
		this->head = node;
		this->tail = head;
	}
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
	}
	put_in_sorted_order(head);
}

template <typename T>
void	FrankList<T>::pop_front()
{
	assert(head != nullptr)

	if (!head->next)
	{
		clear();
		return ;
	}
	if (head->asc)
		head->asc->desc = head->desc;
	if (head->desc)
		head->desc->asc = head->asc;
	head = head->next;
	delete head->prev;
	head->prev = nullptr;
}

template <typename T>
void	FrankList<T>::push_back(const_reference elem)
{
	Node	*node = new Node(elem);

	if (!head)
	{
		head = node;
		tail = head;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	put_in_sorted_order(tail);
}

template <typename T>
void	FrankList<T>::pop_back()
{
	assert(head != nullptr);

	if (!head->next)
	{
		clear();
		return ;
	}
	if (tail->asc)
		tail->asc->desc = tail->desc;
	if (tail->desc)
		tail->desc->asc = tail->asc;
	tail = tail->prev;
	delete tail->next;
	tail->next = nullptr;
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::front() const
{
	assert(head != nullptr);
	return (head->val);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::front()
{
	assert (head != nullptr);
	return (head->val);
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::back() const
{
	assert(head != nullptr);
	return (tail->val);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::back()
{
	assert(head != nullptr);
	return (tail->val);
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::min() const
{
	assert (head != nullptr);
	return (ahead->val);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::min()
{
	assert (head != nullptr);
	return (ahead->val);
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::max() const
{
	assert(head != nullptr);
	return (atail->val);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::max()
{
	assert(head != nullptr);
	return (atail->val);
}

}

#endif