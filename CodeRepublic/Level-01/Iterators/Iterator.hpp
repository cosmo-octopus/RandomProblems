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

#endif