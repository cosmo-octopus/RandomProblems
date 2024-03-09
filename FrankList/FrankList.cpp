#include "FrankList.hpp"

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
	for (input_iterator it = l; it != l; ++it)
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
void	FrankList<T>::resize(size_type s, const_reference init)
{
	size_type	_size = size();

	if (_size > s)
	{
		for (size_type i = 0; i < _size - s; i++)
			pop_back();
	}
	else
	{
		for (size_type i = 0; i < s - _size; i++)
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

	while (curr && curr->val <= ptr->val && curr->asc)
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
	assert(head != nullptr);

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
		tail = node;
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

/* operators */

template <typename T>
const FrankList<T>	&FrankList<T>::operator=(const FrankList<T> &rhv)
{
	if (this != &rhv)
	{
		clear();
		for (auto it = rhv.cbegin(); it != rhv.cend(); ++it)
			push_back(*it);
	}
	return (*this);
}

template <typename T>
const FrankList<T>	&FrankList<T>::operator=(FrankList<T> &&rhv)
{
	clear();

	head = rhv.head;
	tail = rhv.tail;
	ahead = rhv.ahead;
	atail = rhv.atail;

	rhv.head = nullptr;
	rhv.tail = nullptr;
	rhv.ahead = nullptr;
	rhv.atail = nullptr;

	return (*this);
}

template <typename T>
const FrankList<T>	&FrankList<T>::operator=(std::initializer_list<T> init)
{
	clear();

	for (auto i : init)
	    push_back(i);
    return (*this);
}

template <typename T>
bool	FrankList<T>::operator==(const FrankList<T>	&rhv) const
{
	if (this->size() != rhv.size())
		return (false);

	Node	*it1 = this->ahead;
	Node	*it2 = rhv.ahead;

	while (it1)
	{
		if (it1->val != it2->val)
			return (false);
		it1 = it1->next;
		it2 = it2->next;
	}
	return (true);
}

template <typename T>
bool	FrankList<T>::operator!=(const FrankList<value_type>& rhv) const
{
	return !(*this == rhv);
}

template <typename T>
bool	FrankList<T>::operator<(const FrankList &rhv) const
{
	size_type	size1 = this->size();
	size_type	size2 = rhv.size();

	if (size1 < size2)
		return (true);
	if (size1 == size2)
	{
		Node	*it1 = this->ahead;
		Node	*it2 = rhv.ahead;

		while (it1)
		{
			if (it1->val < it2->val)
				return (true);
			if (it1->val > it2->val)
				return (false);
			it1 = it1->next;
			it2 = it2->next;
		}
	}
	return (false);
}

template <typename T>
bool	FrankList<T>::operator<=(const FrankList<T>& rhv) const
{
	return (*this < rhv || *this == rhv);
}

template <typename T>
bool	FrankList<T>::operator>(const FrankList<T>& rhv) const
{
	return !(*this <= rhv);
}

template <typename T>
bool	FrankList<T>::operator>=(const FrankList<T>& rhv) const
{
	return !(*this < rhv);
}

/* iterators */

template <typename T>
typename FrankList<T>::const_iterator	FrankList<T>::cbegin() const
{
	return (const_iterator(head));
}

template <typename T>
typename FrankList<T>::const_iterator	FrankList<T>::cend() const
{
	return (const_iterator(tail->next));
}

template <typename T>
typename FrankList<T>::const_reverse_iterator	FrankList<T>::crbegin() const
{
	return (const_reverse_iterator(tail));
}

template <typename T>
typename FrankList<T>::const_reverse_iterator	FrankList<T>::crend() const
{
	return (const_reverse_iterator(head->prev));
}

template <typename T>
typename FrankList<T>::const_asc_iterator	FrankList<T>::cabegin() const
{
	return (const_asc_iterator(ahead));
}

template <typename T>
typename FrankList<T>::const_asc_iterator	FrankList<T>::caend() const
{
	return (const_asc_iterator(atail->asc));
}

template <typename T>
typename FrankList<T>::const_desc_iterator	FrankList<T>::cdbegin() const
{
	return (const_desc_iterator(atail));
}

template <typename T>
typename FrankList<T>::const_desc_iterator	FrankList<T>::cdend() const
{
	return (const_desc_iterator(ahead->desc));
}

template <typename T>
typename FrankList<T>::const_multi_iterator	FrankList<T>::cmbegin() const
{
	return (const_multi_iterator(head));
}

template <typename T>
typename FrankList<T>::const_multi_iterator	FrankList<T>::cmend() const
{
	return (const_iterator(tail->next));
}

template <typename T>
typename FrankList<T>::const_multi_iterator	FrankList<T>::cmabegin() const
{
	return (const_multi_iterator(ahead));
}

template <typename T>
typename FrankList<T>::const_multi_iterator	FrankList<T>::cmaend() const
{
	return (const_multi_iterator(atail->asc));
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator	FrankList<T>::cmrbegin() const
{
	return (const_multi_reverse_iterator(tail));
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator	FrankList<T>::cmrend() const
{
	return (const_iterator(head->prev));
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator	FrankList<T>::cmrdbegin() const
{
	return (const_multi_reverse_iterator(atail));
}

template <typename T>
typename FrankList<T>::const_multi_reverse_iterator	FrankList<T>::cmrdend() const
{
	return (const_multi_reverse_iterator(ahead->desc));
}

template <typename T>
typename FrankList<T>::iterator	FrankList<T>::begin() 
{
	return (iterator(head));
}

template <typename T>
typename FrankList<T>::iterator	FrankList<T>::end() 
{
	return (iterator(tail->next));
}

template <typename T>
typename FrankList<T>::reverse_iterator	FrankList<T>::rbegin() 
{
	return (reverse_iterator(tail));
}

template <typename T>
typename FrankList<T>::reverse_iterator	FrankList<T>::rend() 
{
	return (reverse_iterator(head->prev));
}

template <typename T>
typename FrankList<T>::asc_iterator	FrankList<T>::abegin() 
{
	return (asc_iterator(ahead));
}

template <typename T>
typename FrankList<T>::asc_iterator	FrankList<T>::aend() 
{
	return (asc_iterator(atail->asc));
}

template <typename T>
typename FrankList<T>::desc_iterator	FrankList<T>::dbegin() 
{
	return (desc_iterator(atail));
}

template <typename T>
typename FrankList<T>::desc_iterator	FrankList<T>::dend() 
{
	return (desc_iterator(ahead->desc));
}

template <typename T>
typename FrankList<T>::multi_iterator	FrankList<T>::mbegin() 
{
	return (multi_iterator(head));
}

template <typename T>
typename FrankList<T>::multi_iterator	FrankList<T>::mend() 
{
	return (iterator(tail->next));
}

template <typename T>
typename FrankList<T>::multi_iterator	FrankList<T>::mabegin() 
{
	return (multi_iterator(ahead));
}

template <typename T>
typename FrankList<T>::multi_iterator	FrankList<T>::maend() 
{
	return (multi_iterator(atail->as));
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator	FrankList<T>::mrbegin() 
{
	return (multi_reverse_iterator(tail));
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator	FrankList<T>::mrend() 
{
	return (iterator(head->prev));
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator	FrankList<T>::mrdbegin() 
{
	return (multi_reverse_iterator(atail));
}

template <typename T>
typename FrankList<T>::multi_reverse_iterator	FrankList<T>::mrdend() 
{
	return (multi_reverse_iterator(ahead->des));
}

/* * */

/* inserts the new element in ascending order */
template <typename T>
template <typename iter>
iter	FrankList<T>::insert_def(iter pos, const_reference val)
{
	assert(pos.ptr != nullptr);

	if (pos.ptr == head)
		push_front(val);
	else
	{
		Node	*node = new Node(val);

		pos.ptr->prev->next = node;
		node->prev = pos.ptr->prev;
		pos.ptr->prev = node;
		node->next = pos.ptr;

		put_in_sorted_order(node);
	}
	return (pos);
}

/* inserts the new element in reverse order */
template <typename T>
template <typename iter>
iter	FrankList<T>::insert_rev(iter pos, const_reference val)
{
	assert(pos.ptr != nullptr);
	insert_def(pos, val);
	++pos;
	return (pos);
}

template <typename T>
template <typename iter>
iter	FrankList<T>::insert(iter pos, size_type s, const_reference val)
{
	/* to perform compile-time assertions */
	static_assert(std::is_base_of<base_iterator, iter>::value == true, "wrong iterator");

	for (size_type i = 0; i < s; ++i)
		pos = insert(pos, val);
	return (pos);
}

template <typename T>
template <typename iter>
iter	FrankList<T>::insert(iter pos, std::initializer_list<T> init)
{
	static_assert(std::is_base_of<base_iterator, iter>::value == true, "wrong iterator");

	for (auto i : init)
		pos = insert(pos, i);
	return (pos);
}

template <typename T>
template <typename iter, typename input_iterator>
iter	FrankList<T>::insert(iter pos, input_iterator f, input_iterator l)
{
	static_assert(std::is_base_of<base_iterator, iter>::value == true, "wrong iterator");

	for (auto i = f; i != l; ++i)
		pos = insert(pos, *i);
	return (pos);
}

// template <typename T>
// template <typename iter>
// iter	FrankList<T>::erase(iter pos)
// {
// 	static_assert(std::is_base_of<base_iterator, iter>::value == true, "uncorrect iterator");
	
// 	Node	*node = pos.ptr;
// 	iter	curr(pos);

// 	++curr;
// 	if (pos.ptr == head)
// 	{
// 		pop_front();
// 		return (curr);
// 	}
// 	if (pos.ptr == tail)
// 	{
// 		pop_back();
// 		return (curr);
// 	}
// 	if (node->prev)
// 		node->prev->next = node->next;
// 	if (node->next)
// 		node->next->prev = node->prev;
// 	if (node->desc)
// 		node->desc->asc = node->asc;
// 	if (node->asc)
//         node->asc->desc = node->desc;
// 	delete pos.ptr;
// 	return (curr);
// }

template <typename T>
template <typename iter>
iter FrankList<T>::erase(iter pos) {
    auto curr = pos.ptr;
    assert(curr != nullptr);

    if (curr->prev) {
        curr->prev->next = curr->next;
    } else {
        head = curr->next;
    }

    if (curr->next) {
        curr->next->prev = curr->prev;
    } else {
        tail = curr->prev;
    }

    auto next = curr->next;
    delete curr;

    return iter(next);
}


template <typename T>
template <typename iter>
iter	FrankList<T>::erase(iter f, iter l)
{
	iter	curr(f);

	while (curr != l)
		curr = erase(curr);
	return (curr);
}

template <typename T>
typename FrankList<T>::size_type	FrankList<T>::remove(const_reference val)
{
	size_type	count = 0;
	iterator	it = begin();

	while (it != end())
	{
		if (*it == val)
		{
			it = erase(it);
			++count;
		}
		else
			++it;
	}
	return (count);
}

template <typename T>
template <typename unary_predicate>
typename FrankList<T>::size_type	FrankList<T>::remove_if(unary_predicate func)
{
	size_type	count = 0;
	iterator	it = begin();

	while (it != end())
	{
		if (func(*it))
		{
			it = erase(it);
			++count;
		}
		else
			++it;
	}
	return (count);
}

template <typename T>
void	FrankList<T>::reverse()
{
	Node	*it = tail;

	std::swap(head, tail);
	while (it)
	{
		std::swap(it->next, it->prev);
		it = it->next;
	}
}

/* bubble sort */
template <typename T>
void	FrankList<T>::sort(bool reversed)
{
	if (!ahead || size() < 2)
		return;

	Node	*current;
	Node	*last = nullptr;
	bool	swapped = true;

    while (swapped)
	{
		swapped = false;
		current = ahead;

		while (current->next != last)
		{
			if ((reversed && current->val < current->next->val) ||
			(!reversed && current->val > current->next->val))
			{
				T temp = current->val;
				current->val = current->next->val;
				current->next->val = temp;
				swapped = true;
			}
			current = current->next;
		}
		last = current;
	}
}

template <typename T>
void	FrankList<T>::organize_left(Node *ptr)
{
	assert(ptr != nullptr);

	if (ptr == head)
		return;

	Node	*prev = ptr->prev;
	Node	*next = ptr->next;

	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	if (prev && prev->prev)
		prev->prev->next = ptr;

	ptr->prev = prev->prev;
	prev->prev = ptr;
	prev->next = next;
	ptr->next = prev;

	if (prev == head)
		head = ptr;
	if (ptr == tail)
		tail = prev;
}

template <typename T>
void FrankList<T>::organize_right(Node *ptr)
{
	assert(ptr != nullptr);

	if (ptr == tail)
		return;

	Node	*prev = ptr->prev;
	Node	*next = ptr->next;

	if (next)
        next->prev = prev;
	if (prev)
        prev->next = next;
	if (next && next->next)
		next->next->prev = ptr;

	ptr->next = next->next;
	next->next = ptr;
	next->prev = prev;
	ptr->prev = next;

	if (next == tail)
		tail = ptr;
	if (ptr == head)
		head = next;
}

template <typename T>
typename FrankList<T>::iterator	FrankList<T>::find(const_reference elem)
{
	iterator	it = begin();

	for (it; it != end() && *it != elem; ++it)
		;
	organize_left(it.ptr);
	return (it);
}

template <typename T>
typename FrankList<T>::iterator	FrankList<T>::rfind(const_reference elem)
{
	reverse_iterator	it = rbegin();

	for (it; it != end() && *it != elem; ++it)
		;
	organize_right(it.ptr);
	return iterator(it);
}

template <typename T>
template <typename unary_predicate>
void	FrankList<T>::traverse(unary_predicate func, bool sorted, bool reversed)
{
	if (!head)
		return ;

    Node	*curr = nullptr;

	if (!sorted && !reversed)
		curr = head;
	else if (!sorted)
		curr = tail;
	else if (!reversed)
		curr = ahead;
	else
		curr = atail;

	while (curr)
	{
		func(curr->val);

		if (!sorted && !reversed)
			curr = curr->next;
		else if (!sorted)
			curr = curr->prev;
		else if (!reversed)
			curr = curr->asc;
		else
			curr = curr->desc;
	}
}


template <typename T>
void	FrankList<T>::print(bool sorted, bool reversed)
{
	if (!head)
	{
		std::cout << "[]" << std::endl;
		return ;
    }
	std::cout << "[ ";
	if (!sorted && !reversed)
	{
		for (auto it = begin(); it != end(); ++it)
			std::cout << *it << " ";
    }
    else if (!sorted)
	{
		for (auto it = rbegin(); it != rend(); ++it)
			std::cout << *it << " ";
    }
    else if (!reversed)
	{
		for (auto it = abegin(); it != aend(); ++it)
			std::cout << *it << " ";
	}
	else
	{
		for (auto it = dbegin(); it != dend(); ++it)
            std::cout << *it << " ";
    }
	std::cout << "]" << std::endl;
}

/*********************************** ITERATORS ***********************************/

template <typename T>
FrankList<T>::base_iterator::base_iterator(Node *ptr): ptr(ptr) {}

template <typename T>
FrankList<T>::base_iterator::~base_iterator()
{
	ptr = nullptr;
}

template <typename T>
bool
FrankList<T>::base_iterator::operator==(const base_iterator &rhv) const
{
	return (ptr == rhv.ptr);
}

template <typename T>
bool
FrankList<T>::base_iterator::operator!=(const base_iterator &rhv) const
{
	return (ptr != rhv.ptr);
}

template <typename T>
FrankList<T>::const_iterator::const_iterator(const base_iterator &rhv): base_iterator(rhv.ptr){}

template <typename T>
FrankList<T>::const_iterator::const_iterator(base_iterator &&rhv)
	: base_iterator(rhv.ptr)
{
	rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::const_iterator::const_iterator(Node *ptr)
	: base_iterator(ptr)
{}

template <typename T>
const typename FrankList<T>::const_iterator	&FrankList<T>::const_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_iterator	&FrankList<T>::const_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::const_iterator::operator*() const
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::const_pointer	FrankList<T>::const_iterator::operator->() const
{
	return (this->ptr);
}

template <typename T>
const typename FrankList<T>::const_iterator	&FrankList<T>::const_iterator::operator++()
{
	this->ptr = this->ptr->next;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_iterator	FrankList<T>::const_iterator::operator++(value_type)
{
	const_iterator tmp(*this);
	++(*this);
	return (tmp);
}

template <typename T>
const typename FrankList<T>::const_iterator	&FrankList<T>::const_iterator::operator--()
{
	this->ptr = this->ptr->prev;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_iterator	FrankList<T>::const_iterator::operator--(value_type)
{
	const_iterator tmp(*this);
	--(*this);
	return (tmp);
}

template <typename T>
FrankList<T>::iterator::iterator(Node *ptr)
	: const_iterator(ptr)
{}

template <typename T>
FrankList<T>::iterator::iterator(const base_iterator &rhv)
	: const_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::iterator::iterator(base_iterator &&rhv)
	: const_iterator(rhv.ptr)
{
	rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::iterator	&FrankList<T>::iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::iterator	&FrankList<T>::iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::iterator::operator*()
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::pointer	FrankList<T>::iterator::operator->()
{
	return (this->ptr);
}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(const base_iterator &rhv)
	: base_iterator(rhv.ptr)
{}


template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(base_iterator &&rhv)
	: base_iterator(rhv.ptr)
{
	rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::const_reverse_iterator::const_reverse_iterator(Node *ptr)
    : base_iterator(ptr)
{}

template <typename T>
const typename FrankList<T>::const_reverse_iterator&
FrankList<T>::const_reverse_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator	&FrankList<T>::const_reverse_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::const_reverse_iterator::operator*() const
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::const_pointer	FrankList<T>::const_reverse_iterator::operator->() const
{
	return (this->ptr);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator	&FrankList<T>::const_reverse_iterator::operator++()
{
	this->ptr = this->ptr->prev;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator	FrankList<T>::const_reverse_iterator::operator++(value_type)
{
	const_reverse_iterator tmp(*this);
	++(*this);
    return (tmp);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator	&FrankList<T>::const_reverse_iterator::operator--()
{
	this->ptr = this->ptr->next;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_reverse_iterator	FrankList<T>::const_reverse_iterator::operator--(value_type)
{
	const_reverse_iterator	tmp(*this);
	--(*this);
	return (tmp);
}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(Node *ptr)
	: const_reverse_iterator(ptr)
{}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator &rhv)
	: const_reverse_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::reverse_iterator::reverse_iterator(base_iterator &&rhv)
	: const_reverse_iterator(rhv.ptr)
{
	rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::reverse_iterator	&FrankList<T>::reverse_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::reverse_iterator	&FrankList<T>::reverse_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::reverse_iterator::operator*()
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::pointer	FrankList<T>::reverse_iterator::operator->()
{
    return (this->ptr);
}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator &rhv)
	: base_iterator(rhv.ptr)
{}


template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator &&rhv)
	: base_iterator(rhv.ptr)
{
	rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::const_asc_iterator::const_asc_iterator(Node *ptr)
	: base_iterator(ptr)
{}

template <typename T>
const typename FrankList<T>::const_asc_iterator	&FrankList<T>::const_asc_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_asc_iterator	&FrankList<T>::const_asc_iterator::operator=(base_iterator	&&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::const_asc_iterator::operator*() const
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::const_pointer	FrankList<T>::const_asc_iterator::operator->() const
{
	return (this->ptr);
}

template <typename T>
const typename FrankList<T>::const_asc_iterator	&FrankList<T>::const_asc_iterator::operator++()
{
	this->ptr = this->ptr->asc;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_asc_iterator	FrankList<T>::const_asc_iterator::operator++(value_type)
{
	const_asc_iterator tmp(*this);
	++(*this);
	return (tmp);
}

template <typename T>
const typename FrankList<T>::const_asc_iterator	&FrankList<T>::const_asc_iterator::operator--()
{
	this->ptr = this->ptr->desc;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_asc_iterator	FrankList<T>::const_asc_iterator::operator--(value_type)
{
	const_asc_iterator tmp(*this);
	--(*this);
	return (tmp);
}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(Node *ptr)
	: const_asc_iterator(ptr)
{}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(const base_iterator &rhv)
	: const_asc_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::asc_iterator::asc_iterator(base_iterator &&rhv)
	: const_asc_iterator(rhv.ptr)
{
	rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::asc_iterator	&FrankList<T>::asc_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::asc_iterator	&FrankList<T>::asc_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::asc_iterator::operator*()
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::pointer	FrankList<T>::asc_iterator::operator->()
{
	return (this->ptr);
}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator &rhv)
	: base_iterator(rhv.ptr)
{}


template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator &&rhv)
	: base_iterator(rhv.ptr)
{
	rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::const_desc_iterator::const_desc_iterator(Node *ptr)
	: base_iterator(ptr)
{}

template <typename T>
const typename FrankList<T>::const_desc_iterator	&FrankList<T>::const_desc_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_desc_iterator	&FrankList<T>::const_desc_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::const_desc_iterator::operator*() const
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::const_pointer	FrankList<T>::const_desc_iterator::operator->() const
{
	return (this->ptr);
}

template <typename T>
const typename FrankList<T>::const_desc_iterator	&FrankList<T>::const_desc_iterator::operator++()
{
	this->ptr = this->ptr->desc;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_desc_iterator	FrankList<T>::const_desc_iterator::operator++(value_type)
{
    const_desc_iterator tmp(*this);
    ++(*this);
    return (tmp);
}

template <typename T>
const typename FrankList<T>::const_desc_iterator	&FrankList<T>::const_desc_iterator::operator--()
{
	this->ptr = this->ptr->asc;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_desc_iterator	FrankList<T>::const_desc_iterator::operator--(value_type)
{
	const_desc_iterator tmp(*this);
	--(*this);
	return (tmp);
}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(Node *ptr)
	: const_desc_iterator(ptr)
{}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(const base_iterator &rhv)
	: const_desc_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::desc_iterator::desc_iterator(base_iterator &&rhv)
    : const_desc_iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::desc_iterator	&FrankList<T>::desc_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::desc_iterator	&FrankList<T>::desc_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::desc_iterator::operator*()
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::pointer	FrankList<T>::desc_iterator::operator->()
{
	return (this->ptr);
}

template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(const base_iterator &rhv)
	: base_iterator(rhv.ptr)
{}


template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(base_iterator &&rhv)
	: base_iterator(rhv.ptr)
{
	rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::const_multi_iterator::const_multi_iterator(Node *ptr)
	: base_iterator(ptr)
{}

template <typename T>
const typename FrankList<T>::const_multi_iterator	&FrankList<T>::const_multi_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_iterator	&FrankList<T>::const_multi_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::const_multi_iterator::operator*() const
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::const_pointer	FrankList<T>::const_multi_iterator::operator->() const
{
	return (this->ptr);
}

template <typename T>
const typename FrankList<T>::const_multi_iterator	&FrankList<T>::const_multi_iterator::operator++()
{
	if (mode)
        this->ptr = this->ptr->next;
    else
        this->ptr = this->ptr->asc;
    return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_iterator	FrankList<T>::const_multi_iterator::operator++(value_type)
{
	const_multi_iterator tmp(*this);
	++(*this);
	return (tmp);
}

template <typename T>
const typename FrankList<T>::const_multi_iterator	&FrankList<T>::const_multi_iterator::operator--()
{
	if (mode)
        this->ptr = this->ptr->desc;
    else
        this->ptr = this->ptr->prev;
    return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_iterator	FrankList<T>::const_multi_iterator::operator--(value_type)
{
	const_multi_iterator tmp(*this);
	--(*this);
	return (tmp);
}

template <typename T>
void	FrankList<T>::const_multi_iterator::chmod()
{
	mode = !mode;
}

template <typename T>
FrankList<T>::multi_iterator::multi_iterator(Node *ptr)
	: const_multi_iterator(ptr)
{}

template <typename T>
FrankList<T>::multi_iterator::multi_iterator(const base_iterator &rhv)
	: const_multi_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::multi_iterator::multi_iterator(base_iterator &&rhv)
	: const_multi_iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::multi_iterator	&FrankList<T>::multi_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::multi_iterator	&FrankList<T>::multi_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::multi_iterator::operator*()
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::pointer	FrankList<T>::multi_iterator::operator->()
{
	return (this->ptr);
}

template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator &rhv)
	: base_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator &&rhv)
	: base_iterator(rhv.ptr)
{
	rhv.ptr = nullptr;
}

template <typename T>
FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(Node *ptr)
	: base_iterator(ptr)
{}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator	&FrankList<T>::const_multi_reverse_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator	&FrankList<T>::const_multi_reverse_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::const_reference	FrankList<T>::const_multi_reverse_iterator::operator*() const
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::const_pointer	FrankList<T>::const_multi_reverse_iterator::operator->() const
{
	return (this->ptr);
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator	&FrankList<T>::const_multi_reverse_iterator::operator++()
{
	if (mode)
		this->ptr = this->ptr->prev;
    else
		this->ptr = this->ptr->desc;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator	FrankList<T>::const_multi_reverse_iterator::operator++(value_type)
{
	const_multi_reverse_iterator tmp(*this);
	++(*this);
	return (tmp);
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator	&FrankList<T>::const_multi_reverse_iterator::operator--()
{
	if (mode)
		this->ptr = this->ptr->next;
	else
		this->ptr = this->ptr->asc;
	return (*this);
}

template <typename T>
const typename FrankList<T>::const_multi_reverse_iterator	FrankList<T>::const_multi_reverse_iterator::operator--(value_type)
{
	const_multi_reverse_iterator tmp(*this);
	--(*this);
	return tmp;
}

template <typename T>
void	FrankList<T>::const_multi_reverse_iterator::chmod()
{
    mode = !mode;
}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(Node *ptr)
	: const_multi_reverse_iterator(ptr)
{}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(const base_iterator &rhv)
	: const_multi_reverse_iterator(rhv.ptr)
{}

template <typename T>
FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(base_iterator &&rhv)
	: const_multi_reverse_iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

template <typename T>
const typename FrankList<T>::multi_reverse_iterator	&FrankList<T>::multi_reverse_iterator::operator=(const base_iterator &rhv)
{
	this->ptr = rhv.ptr;
	return (*this);
}

template <typename T>
const typename FrankList<T>::multi_reverse_iterator	&FrankList<T>::multi_reverse_iterator::operator=(base_iterator &&rhv)
{
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return (*this);
}

template <typename T>
typename FrankList<T>::reference	FrankList<T>::multi_reverse_iterator::operator*()
{
	return (this->ptr->val);
}

template <typename T>
typename FrankList<T>::pointer	FrankList<T>::multi_reverse_iterator::operator->()
{
	return (this->ptr);
}

}