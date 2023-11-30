#ifndef __STACK_H__
# define __STACK_H__

# include <limits>
# include <utility>
# include <iostream>
# include <stdexcept>

template <typename T>
class	Stack
{
	private:
		T		*data;
		size_t	size;
		size_t	capacity;

		void	reserve(size_t capacity);
		void	resize(size_t	size);
	public:
		Stack(void);
		~Stack();

		size_t	get_size(void);
		void	push(const T &g);
		T		pop(void);
		bool	empty(void);
		T		&top(void);

		void	printAll(void) const;
};

# include "Stack.hpp"

#endif