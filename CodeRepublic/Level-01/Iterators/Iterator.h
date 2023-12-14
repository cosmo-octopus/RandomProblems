#ifndef __ITERATOR_H__
# define __ITERATOR_H__

# include "../Containers/Vector/Vector.h"

template <typename T>
class	Iterator
{
	private:
		T	*ptr;

	public:
		Iterator(void): ptr(nullptr){};
		Iterator(const Iterator<T> &other);
		~Iterator(){};

		/* Dereferencing operator */
		T			&operator*();
		/* Member access operator */
		T			*operator->();
		/* Subscript operator (for random access iterators) */
		T			&operator[](int index);
		/* Pre-increment operator */
		Iterator<T>	&operator++();
		/* Post-increment operator */
		Iterator<T>	operator++(int);
		/* Pre-decrement operator */
		Iterator<T>	&operator--();
		/* Post-decrement operator */
		Iterator<T>	operator--(int);
		/* Addition operator (for random access iterators) */
		Iterator<T>	operator+(int n) const;
		/* Subtraction operator (for random access iterators) */
		Iterator<T>	operator-(int n) const;
    	/* Compound addition operator (for random access iterators) */
		Iterator<T>	&operator+=(int n);
		/* Compound subtraction operator (for random access iterators) */
		Iterator<T>	&operator-=(int n);
		/* Equality comparison operator */
		bool		operator==(const Iterator<T> &other) const;
		/* Inequality comparison operator*/
		bool		operator!=(const Iterator<T> &other) const;
};

# include "Iterator.hpp"

// Iterator	operator+(const size_t off)
// {
// 	Iterator	t = *this;
// 	for(int i = 0; i <= off; i++)
// 	{
// 		++t;
// 	}
// 	return (t);
// }

// Iterator	&operator+= (const size_t off)
// {
// 	for (int i = 0; i < off; i++)
// 		++(*this);
// 	return (*this);
// }

#endif