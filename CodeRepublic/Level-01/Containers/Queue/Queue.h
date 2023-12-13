#ifndef __QUEUE_H__
# define __QUEUE_H__

# include <limits>
# include <utility>
# include <iostream>
# include <stdexcept>

template <typename T>
class	Queue
{
	private:
		T		*data;
		size_t	size;
		size_t	realSize;
		size_t	capacity;
		size_t	start;

		void	reserve(size_t capacity);
		void	resize(size_t size);
	public:
		Queue(void);
		~Queue();

		void	enqueue(const T &elem);
		T		dequeue(void);
		T		&front(void);
		T		&rear(void);
		bool	isEmpty(void) const;
		size_t	get_size(void);
		void	printAll(void);
};

# include "Queue.hpp"

#endif