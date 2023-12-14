#ifndef __ITERATOR_HPP__
# define __ITERATOR_HPP__

# include "Iterator.h"

template <typename T>
T	&Iterator<T>::operator*(void)
{
	return (*ptr);
}

template <typename T>
T	*Iterator<T>::operator->(void)
{
	return (ptr);
}

template <typename T>
T	&Iterator<T>::operator[](size_t index)
{
	return (ptr[index]);
}

template <typename T>
Iterator<T>	&Iterator<T>::operator++(void)
{
	++this->ptr;
	return (*this);
}

template <typename T>
Iterator<T>	Iterator<T>::operator++(int)
{
	Iterator<T>	temp = *this;

	this->ptr++;
	return (temp);
}

template <typename T>
Iterator<T>	&Iterator<T>::operator--(void)
{
	--this->ptr;
	return (*this);
}

template <typename T>
Iterator<T>	Iterator<T>::operator--(int)
{
	Iterator<T>	temp = *this;

	--this->ptr;
	return (temp);
}

#endif