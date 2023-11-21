#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

/***************************************************************/

# include <iostream>
# include <limits>

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
   		~Vector();

		size_t	get_size() const;
		size_t	get_capacity() const;
		void	vec_print(void) const;
		void	push_back(const T &elem);
		size_t	max_size(void) const;
		void	reserve(size_t capacity);
		void	resize(size_t size);
		bool	empty(void) const;
		void	shrink_to_fit(void);
};

/***************************************************************/

template <typename T>
Vector<T>::Vector(void): array(nullptr), capacity(0), size(0)
{
}

template <typename T>
Vector<T>::~Vector(void)
{
	delete[] this->array;
}

template <typename T>
size_t	Vector<T>::get_size() const
{
	return (this->size);
}

template <typename T>
size_t	Vector<T>::get_capacity() const
{
	return (this->capacity);
}

template <typename T>
void	Vector<T>::push_back(const T &elem)
{
    T	*array;

	if (size >= capacity)
	{
        if (capacity == 0)
            capacity = 1;
        else
            capacity *= 2;
        array = new T[capacity];
        for (size_t i = 0; i < size; i++)
            array[i] = this->array[i];
        delete[] this->array;
        this->array = array;
        this->array[size++] = elem;
	}
    else
        this->array[size++] = elem;
}

template <typename T>
void	Vector<T>::vec_print(void) const
{
	for (size_t i = 0; i < this->size; i++)
		std::cout << this->array[i] << " ";
	std::cout << std::endl;
}

template <typename T>
size_t	Vector<T>::max_size(void) const
{
	return (std::numeric_limits<size_t>::max());
}

template <typename T>
void	Vector<T>::reserve(size_t capacity)
{
	T	*arr;

	if (capacity > this->capacity)
	{
		arr = new T[capacity];
		for (size_t i = 0; i < this->size; i++)
			arr[i] = this->array[i];
		delete[] this->array;
		this->array = arr;
		this->capacity = capacity;
	}
}

template <typename T>
void	Vector<T>::resize(size_t size)
{
	if (size < this->size)
		this->size = size;
	else if (size > this->size)
	{
		reserve(size);
		while (this->size < size)
		{
			this->array[this->size] = T();
			this->size++;
		}
	}

}

template <typename T>
bool	Vector<T>::empty(void) const
{
	return (this->size == 0);
}

template <typename T>
void	Vector<T>::shrink_to_fit(void)
{
	T	*array;
	
	if (this->size < this->capacity)
	{
		if (size == 0)
		{
			delete[] this->array;
			this->array = nullptr;
		}
		else
		{
			array = new T[this->size];
			for (size_t i = 0; i < this->size; i++)
				array[i] = this->array[i];
			delete[] this->array;
			this->array = array;
		}
		capacity = size;
	}
}

#endif