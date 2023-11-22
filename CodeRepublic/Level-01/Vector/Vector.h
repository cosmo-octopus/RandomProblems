#ifndef __VECTOR_H__
# define __VECTOR_H__

/***************************************************************/

# include <iostream>
# include <limits>
# include <stdexcept>
# include <utility>

/***************************************************************/

template <typename T>
class	Vector
{
	private:
    	T*		array;
    	size_t	capacity;
    	size_t	size;
	public:
    	Vector(void);
		template <typename... Args>
		Vector(size_t count, Args&&... args);
   		~Vector();

		size_t	get_size() const;
		size_t	get_capacity() const;
		void	print(void) const;
		void	push_back(const T &elem);
		size_t	max_size(void) const;
		void	reserve(size_t capacity);
		void	resize(size_t size);
		bool	empty(void) const;
		void	shrink_to_fit(void);
		const T	&at(size_t index) const;
		const T	&front(void) const;
		const T	&back(void) const;
		const T	*data(void) const;
		void	clear(void);
		void	assign(size_t count, const T &value);
		void	pop_back(void);
		void	insert(size_t position, const T &value);
		void	erase(size_t position);
		void	erase(size_t first, size_t last);
		void	swap(Vector &other);
		template <class... Args>
		void	emplace(size_t index, Args&&... args); // variadic template parameter pack
};

/***************************************************************/

# include "Vector.hpp"

#endif