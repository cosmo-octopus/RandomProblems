#ifndef __STACK_HPP__
# define __STACK_HPP__

# include "Stack.h"

template <typename T>
Stack<T>::Stack(void): data(nullptr), size(0), capacity(0)
{
}

template <typename T>
Stack<T>::~Stack()
{
	if (data)
		delete [] data;
}

template <typename T>
size_t	Stack<T>::get_size(void)
{
	return (this->size);
}

template <typename T>
void	Stack<T>::reserve(size_t capacity)
{
	T	*data;

	if (capacity > this->capacity)
	{
		data = new T[capacity];
		if (this->data)
		{
			for (size_t i = 0; i < this->size; i++)
				data[i] = this->data[i];
			delete [] this->data;
		}
		this->data = data;
		this->capacity = capacity;
	}
}

template <typename T>
void	Stack<T>::push(const T &g)
{
	if (size == capacity)
		reserve((capacity == 0) ? 1 : capacity * 2);
	data[size] = g;
	this->size++;
}

template <typename T>
void	Stack<T>::printAll(void) const
{
	if (this->size == 0)
        throw std::out_of_range("Stack is empty");
	for (size_t i = this->size; i > 0; i--)
		std::cout << data[i - 1] << " ";
	std::cout << std::endl;
}

template <typename T>
void	Stack<T>::resize(size_t size)
{
	T	*data = new T[size];

	if (this->data)
	{
		for (size_t i = 0; i < size; i++)
			data[i] = this->data[i];
		delete [] this->data;
	}
	this->data = data;
	this->size = size;
	this->capacity = size;
}

template <typename T>
T	Stack<T>::pop(void)
{
	T	tmp;

	if (size == 0)
        throw std::out_of_range("Stack is empty");
	if (size <= capacity / 4)
		resize(size);
	tmp = data[size - 1];
	this->size--;
	return (tmp);
}

template <typename T>
bool	Stack<T>::empty(void)
{
	return (this->size == 0);
}

template <typename T>
T	&Stack<T>::top(void)
{
	return (data[size - 1]);
}

#endif