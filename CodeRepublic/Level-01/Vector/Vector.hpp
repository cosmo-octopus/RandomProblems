#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include <iostream>

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

		void	vec_print(void) const;
		size_t	get_size() const;
		size_t	get_capacity() const;
		void	push_back(const T &elem);
};

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
    T	*new_array;

	if (size >= capacity)
	{
        if (capacity == 0)
            capacity = 1;
        else
            capacity *= 2;
		new_array = new T[capacity];
        for (size_t i = 0; i < size; i++)
            new_array[i] = this->array[i];
        delete[] array;
        this->array = new_array;
        this->array[size++] = elem;
	}
}

template <typename T>
void	Vector<T>::vec_print(void) const
{
	for (size_t i = 0; i < this->size; i++)
		std::cout << this->array[i] << " ";
	std::cout << std::endl;
}

#endif