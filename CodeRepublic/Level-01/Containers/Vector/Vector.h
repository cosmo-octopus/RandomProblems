#ifndef __VECTOR_H__
# define __VECTOR_H__

/***************************************************************/

# include <limits>
# include <utility>
# include <iostream>
# include <stdexcept>

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
		Vector(std::initializer_list<T> list);
		Vector(Vector&& other) noexcept;
   		~Vector();

		size_t				get_size(void) const;
		size_t				get_capacity(void) const;
		void				print(void) const;
		void				push_back(const T &elem);
		size_t				max_size(void) const;
		void				reserve(size_t capacity);
		void				resize(size_t size);
		bool				empty(void) const;
		void				shrink_to_fit(void);
		const T				&at(size_t index) const;
		const T				&front(void) const;
		const T				&back(void) const;
		T					*begin(void) const;
		T					*end(void) const;
		const T				*data(void) const;
		void				clear(void);
		void				assign(size_t count, const T &value);
		void				pop_back(void);
		void				insert(size_t position, const T &value);
		void				erase(size_t position);
		void				erase(size_t first, size_t last);
		void				swap(Vector &other);
		template <class... Args>
		void				emplace(size_t index, Args&&... args); // variadic template parameter pack
		template <typename... Args>
		void				emplace_back(Args&&... args);
		template <typename U>
		friend std::ostream &operator<<(std::ostream &os, const Vector<U> &vec);
		Vector<T>			&operator=(const Vector &other);
		Vector<T>			&operator=(Vector&& other) noexcept;
};

/***************************************************************/

# include "Vector.hpp"

#endif