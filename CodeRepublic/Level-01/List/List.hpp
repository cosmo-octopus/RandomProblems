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
		node->next = nullptr;
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

template <typename T>
List<T>	&List<T>::operator= (const List &list)
{
	clear();

	Node	*node = nullptr;
	Node	*iter = list.head;
	Node	*curr = nullptr;
	size_t	i = 0;

	while (iter)
	{
		node = new Node(iter->data);
		if (i == 0)
		{
			this->head = node;
			curr = this->head;
		}
		curr->next = node;
		curr = curr->next;
		if (i == list.size - 1)
		{
			this->tail = node;
			node->next = nullptr;
		}
		iter = iter->next;
		i++;
	}
	return (*this);
}

template <typename T>
void	List<T>::pop_back(void)
{
	Node	*iter;

	if (!this->head)
		throw std::out_of_range("List is empty");
	iter = this->head;
	while (iter->next->next)
		iter = iter->next;
	delete iter->next;
	this->tail = iter;
	iter->next = nullptr;
	this->size --;
}

template <typename T>
void	List<T>::pop_front(void)
{
	Node	*tmp;

	if (!this->head)
		throw std::out_of_range("List is empty");
	tmp = this->head;
	this->head = this->head->next;
	delete tmp;
	this->size --;
}

template <typename T>
bool	List<T>::empty(void)
{
	return (this->size == 0);
}

template <typename T>
void	List<T>::unique(void)
{
	Node	*curr;
	Node	*runner;
	Node	*dupl;

    if (!this->head || !(this->head->next))
        return;
    curr = this->head;
    while (curr)
	{
    	runner = curr;
        while (runner->next)
		{
            if (runner->next->data == curr->data)
			{
                dupl = runner->next;
                runner->next = runner->next->next;
                delete dupl;
            }
			else
                runner = runner->next;
        }
        curr = curr->next;
    }
}

template <typename T>
List<T>	&List<T>::merge(List<T> &other)
{
	Node	*tmp1 = this->head;
	Node	*tmp2 = other.head;
	Node	*curr;

	if (!this->head)
	{
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		return (*this);
	}
	if (!other.head)
		return (*this);
	if (tmp1 && tmp2)
	{
		if (tmp2->data <= tmp1->data)
		{
			this->head = tmp2;
			tmp2 = tmp2->next;
		}
	}
	curr = this->head;
	while (tmp1 && tmp2)
	{
		if (tmp1->data <= tmp2->data)
		{
			curr->next = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			curr->next = tmp2;
			tmp2 = tmp2->next;
		}
		curr = curr->next;
	}
	if (tmp1)
		curr->next = tmp1;
	else if (tmp2)
	{
		curr->next = tmp2;
		this->tail = other.tail;
	}
	this->size += other.size;
	other.head = nullptr;
	other.tail = nullptr;
	other.size = 0;
	return (*this);
}

template <typename T>
typename List<T>::Node	*List<T>::mergeSort(Node* head)
{
    Node	*middle = getMiddle(head);
    Node	*nextToMiddle = middle->next;
	Node	*left;
	Node	*right;

    if (!head || !head->next)
        return (head);
    middle->next = nullptr;
	left = mergeSort(head);
	right = mergeSort(nextToMiddle);
    return (merge(left, right));
}

template <typename T>
typename List<T>::Node	*List<T>::getMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    if (!head)
        return (head);
    while (fast)
	{
        fast = fast->next;
        if (fast)
		{
            slow = slow->next;
            fast = fast->next;
        }
    }
    return (slow);
}

template <typename T>
typename List<T>::Node	*List<T>::merge(Node* left, Node* right)
{
    Node* result = nullptr;

    if (!left)
        return (right);
    if (!right)
        return (left);
    if (left->data <= right->data)
	{
        result = left;
        result->next = merge(left->next, right);
    }
	else
	{
        result = right;
        result->next = merge(left, right->next);
    }
    return (result);
}

/* Modified mergeSort function to be called from the outside */
template <typename T>
void	List<T>::sort(void)
{
	Node	*iter;

    this->head = mergeSort(this->head);
	iter = this->head;
	while (iter->next)
		iter = iter->next;
	this->tail = iter;
}

template <typename T>
void	List<T>::reverse(void)
{
	Node	*curr;
	Node	*prev = nullptr;
	Node	*next = nullptr;

	if (!head)
		throw std::out_of_range("List is empty");
	curr = this->head;
	this->head = this->tail;
	this->tail = curr;
	while(curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
}

#endif