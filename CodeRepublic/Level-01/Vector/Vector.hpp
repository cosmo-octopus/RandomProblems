#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

template <typename T>
Vector<T>::Vector(void): array(nullptr), capacity(0), size(0)
{
}

template <typename T>
template <typename... Args>
Vector<T>::Vector(size_t count, Args&&... args): array(new T[count]), capacity(count), size(count)
{
    for (size_t i = 0; i < count; ++i)
        array[i] = T(std::forward<Args>(args)...);
}

template <typename T>
Vector<T>::~Vector(void)
{
	delete[] this->array;
}

/* returns the current number of elements in the vector */
template <typename T>
size_t	Vector<T>::get_size() const
{
	return (this->size);
}

/* returns the current capacity of the vector (i.e., maximum number of elements it can hold without reallocation) */
template <typename T>
size_t	Vector<T>::get_capacity() const
{
	return (this->capacity);
}

/* adds an element to the end of the vector */
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

/* prints the elements of the vector */
template <typename T>
void	Vector<T>::print(void) const
{
	for (size_t i = 0; i < this->size; i++)
		std::cout << this->array[i] << " ";
	std::cout << std::endl;
}

/* returns the maximum number of elements that the vector can theoretically hold based on system limitations */
template <typename T>
size_t	Vector<T>::max_size(void) const
{
	return (std::numeric_limits<size_t>::max());
}

/* allocates memory to accommodate a specified capacity without changing the vector's size */
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

/* resizes the vector to the specified size, either by adding default-initialized elements or removing excess elements if needed */
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

/* checks if the vector is empty (contains no elements) and returns true if it's empty, false otherwise */
template <typename T>
bool	Vector<T>::empty(void) const
{
	return (this->size == 0);
}

/* reduces the capacity of the container to fit its current size */
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

/* returns a constant reference to the element at the specified index */
template <typename T>
const T	&Vector<T>::at(size_t index) const
{
	if (index >= this->size)
		throw std::out_of_range("Index out of range");
	return (this->array[index]);
}

/* retrieves a reference to the first element in the container */
template <typename T>
const T	&Vector<T>::front(void) const
{
	if (this->size == 0)
		throw std::out_of_range("Vector is empty");
	return (this->array[0]);
}

/* retrieves a reference to the last element in the container */
template <typename T>
const T	&Vector<T>::back(void) const
{
	if (this->size == 0)
		throw std::out_of_range("Vector is empty");
	return (this->array[this->size - 1]);
}

/* returns a pointer to the underlying array used to store the elements */
template <typename T>
const T	*Vector<T>::data(void) const
{
	return (this->array);
}

/* removes all elements from the container, leaving it with a size of 0
note: the memory allocation remains unchanged; elements are logically removed but memory isn't deallocated here */
template <typename T>
void	Vector<T>::clear(void)
{
	this->size = 0;
}

/* replaces the contents of the vector with the provided elements */
template <typename T>
void	Vector<T>::assign(size_t count, const T &value)
{
	clear();
	reserve(count);
	for (size_t i = 0; i < count; i++)
		this->array[i] = value;
	this->size = count;
}

/* removes the last element from the container, effectively reducing its size by one */
template <typename T>
void	Vector<T>::pop_back(void)
{
	if (this->size > 0)
		size--;
}

/* inserts elements at a specified position within the container */
template <typename T>
void	Vector<T>::insert(size_t position, const T &value)
{
	if (position > this->size)
		throw std::out_of_range("Invalid position for insertion");
	if (this->size >= this->capacity)
		reserve(this->capacity * 2);
	for (size_t i = 0; i > position; i--)
		this->array[i] = this->array[i - 1];
	this->array[position] = value;
	size++;
}

/* removes elements from a specific position */
template <typename T>
void	Vector<T>::erase(size_t position)
{
	if (position > this->size)
		throw std::out_of_range("Invalid position for erasing");
	for (size_t i = position; i < this->size - 1; i++)
		this->array[i] = this->array[i + 1];
	this->size--;
}

/* removes elements within a range [first, last) */
template <typename T>
void	Vector<T>::erase(size_t first, size_t last)
{
	size_t	range;
	if (first >= this->size || last > this->size || first >= last)
        throw std::out_of_range("Invalid range for erasing");
	range = last - first;
	for (size_t i = last; i < this->size - 1; i++)
		this->array[i - range] = this->array[i];
	this->size -= range;
}

/* exchanges the contents of two containers */
template <typename T>
void	Vector<T>::swap(Vector &other)
{
	std::swap(this->array, other.array);
	std::swap(this->capacity, other.capacity);
	std::swap(this->size, other.size);
}

/* extends the set container by inserting new elements into the container.
elements are built directly (neither copied nor moved) */
template <typename T>
template <typename... Args>
void	Vector<T>::emplace(size_t index, Args&&... args)
{
    if (index > size)
        throw std::out_of_range("Index out of range");
    if (size >= capacity)
        reserve((capacity == 0) ? 1 : capacity * 2);
    if (index < size)
        for (size_t i = size; i > index; --i)
    		array[i] = std::move(array[i - 1]);
    new (&array[index]) T(std::forward<Args>(args)...);
    ++size;
}

/* a friend function is a function that is not a member of a class but has access to the
private and protected members of that class. It is declared within the class using the friend keyword */
template <typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& vec) {
    os << "[ ";
    for (size_t i = 0; i < vec.size; ++i)
        os << vec.array[i] << " ";
    os << "]";
    return os;
}

#endif