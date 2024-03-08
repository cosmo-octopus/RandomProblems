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

// using value_type = T;
// using reference = value_type&;
// using const_reference = const value_type&;
// using size_type = std::size_t;
// using pointer = value_type*;
// using const_pointer = const value_type*;

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


}

#endif