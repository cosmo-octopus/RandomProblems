#ifndef __QUEUE_HPP__
# define __QUEUE_HPP__

# include "Queue.h"

template <typename T>
Queue<T>::Queue(void): data(nullptr), size(0), realSize(0), capacity(0), start(0)
{
}

template <typename T>
Queue<T>::~Queue()
{
	if (data)
		delete[] data;
}

template <typename T>
void	Queue<T>::reserve(size_t capacity)
{
	T	*data;

	if (this->size < capacity)
	{
		data = new T[capacity];
		if (this->data)
		{
			for (size_t i = start; i < this->size; i++)
				data[i] = this->data[i];
			delete [] this->data;
		}
		this->data = data;
		this->capacity = capacity;
	}
}

template <typename T>
void	Queue<T>::resize(size_t size)
{
	T	*data;

	if (this->size > size)
	{
		data = new T[size];
		if (this->data)
		{
			for (size_t i = start; i < size; i++)
				data[i] = this->data[i];
			delete[] this->data;
		}
		this->data = data;
		this->size = size;
		this->realSize = size;
		this->capacity = size;
	}
}

template <typename T>
void	Queue<T>::printAll(void)
{
	if (size == 0)
		std::cout << "Queue is empty" << std::endl;
	std::cout << "[ ";
	for(size_t i = start; i < realSize; i++)
		std::cout << data[i] << " ";
	std::cout << "]" << std::endl;
}

template <typename T>
void	Queue<T>::enqueue(const T &elem)
{
	if (realSize == capacity)
		reserve((capacity == 0) ? 1 : capacity * 2);
	for (size_t i = realSize; i > start; i--)
		data[i] = data[i - 1];
	data[start] = elem;
	this->size++;
	this->realSize++;
}

template <typename T>
size_t	Queue<T>::get_size(void)
{
	return (this->size);
}

template <typename T>
T	Queue<T>::dequeue(void)
{
	T	elem;

	if (size == 0)
		throw std::out_of_range("Queue is empty");
	elem = data[start];
	start++;
	size--;
	return (elem);
}

template <typename T>
T	&Queue<T>::front(void)
{
	return (data[start]);
}

template <typename T>
T	&Queue<T>::rear(void)
{
	return (data[realSize - 1]);
}

template  <typename T>
bool	Queue<T>::isEmpty(void) const
{
	return (size == 0);
}

#endif