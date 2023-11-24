#ifndef __VECTORBOOL_HPP__
# define __VECTORBOOL_HPP__

# include "VectorBool.h"

VectorBool::VectorBool(void): data(nullptr), size(0), capacity(0)
{
}

VectorBool::~VectorBool()
{
	delete[] data;
}

/* returns the current size */
size_t	VectorBool::get_size(void) const
{
	return (this->size);
}

/* returns the maximum possible size that the VectorBool can theoretically reach based on system limitations */
size_t	VectorBool::max_size(void) const
{
	return (std::numeric_limits<size_t>::max());
}

/* calculates the byte index and bit offset to access the required bit */
bool	VectorBool::at(size_t index) const
{
	size_t	byteIndex = index / 8;
	size_t	bitOffset = index % 8;

	if (index >= this->size)
		throw std::out_of_range("Index out of range");
	return ((this->data[byteIndex] >> bitOffset) & 1);
}

/* adds an element to the end */
void	VectorBool::push_back(bool value)
{
	size_t	byteIndex = this->size / 8;
	size_t	bitOffset = this->size % 8;

	if (this->size / 8 >= this->capacity)
	{
		reserve(this->capacity == 0 ? 1 : this->capacity * 2);
		byteIndex = this->size / 8;
	}
	if (value)
		this->data[byteIndex] |= (1 << bitOffset); // Set the bit to 1
	else
		this->data[byteIndex] &= ~(1 << bitOffset); // Clear the bit at bitOffset
	this->size++;
}

/* removes the last element */
void	VectorBool::pop_back(void)
{
	size_t	byteIndex = this->size / 8;
	size_t	bitOffset = this->size % 8;

	if (this->size > 0)
	{
		this->data[byteIndex] &= ~(1 << bitOffset);
		this->size--;
	}
	else if (this->size == 0)
	{
		delete[] this->data;
		this->data = nullptr;
		this->capacity = 0;
	}
	else
		throw std::out_of_range("pop_back() on an empty vector");
}

/* allocates memory to accommodate a specified number of elements without changing the size */
void	VectorBool::reserve(size_t capacity)
{
	unsigned char	*data;
	size_t			cpySize;
	
	if (capacity > this->capacity)
	{
		data = new unsigned char[capacity];
		if (this->data)
		{
			cpySize = this->size / 8;
			if (this->size % 8)
				cpySize++;
			for (size_t i = 0; i < cpySize; i++)
				data[i] = this->data[i];
			delete [] this->data;
		}
		this->data = data;
		this->capacity = capacity;
	}
}

void	VectorBool::print(void)
{
	for (size_t i = 0; i < this->size; i++)
		std::cout << at(i) << " ";
	std::cout << std::endl;
}

void	VectorBool::resize(size_t size)
{
	if (size < this->size)
		this->size = size;
	else if (size > this->size)
	{
		reserve(size);
		while (this->size < size)
		{
			this->data[this->size] = bool();
			this->size++;
		}
	}
}

#endif