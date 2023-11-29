#ifndef __VECTORBOOL_H__
# define __VECTORBOOL_H__

# include <limits>
# include <utility>
# include <iostream>
# include <stdexcept>
# include <bits/stdc++.h> 

class	VectorBool
{
	private:
		unsigned char				*data;
		size_t						size;
		size_t						capacity;
		// static const unsigned char	_bit_mask;
	public:
		VectorBool(void);
		~VectorBool();

		class BoolReference
		{
			private:
				unsigned char	&_character;
				size_t			_index;
				bool			_bit;

			public:
				BoolReference(unsigned char &character, size_t	index);
				BoolReference(unsigned char &character, size_t	index, const bool &bit);
				~BoolReference();

				bool	getBit(void);
				void	changeBit(const bool &bit);
				operator bool();
				BoolReference	&operator= (const bool &bit);
				// BoolReference	&operator =(const bool &bit);


		};

		size_t	get_size(void) const;
		size_t	max_size(void) const;
		void	push_back(bool value);
		void	pop_back(void);
		bool	at(size_t index) const;
		// bool	At(size_t index);
		VectorBool::BoolReference At(size_t index);
		// bool	At(size_t index, bool flag);
		void	reserve(size_t capacity);
		void	print(void);
		void	resize(size_t size);
		void	operator =(bool flag);
};

VectorBool::BoolReference::BoolReference(unsigned char &character, size_t index): _character(character), _index(index), _bit(0)
{
	// _bit = character & (1 << _index % 8);
	_bit = (character >> (index % 8)) & 1;
}

VectorBool::BoolReference::BoolReference(unsigned char &character, size_t index, const bool &bit): _character(character), _index(index), _bit(bit)
{
	if (bit)
        _character |= (1u << (_index % 8)); // Set the bit to 1
    else
        _character &= ~(1u << (_index % 8)); // Set the bit to 0
    _bit = bit;
	// character = character & (bit << _index % 8);
	// _bit = character & (1 << _index % 8);
}

VectorBool::BoolReference::~BoolReference()
{
}

bool	VectorBool::BoolReference::getBit(void)
{
	return (_bit);
}

VectorBool::BoolReference::operator bool()
{
	return (this->_bit);
}

void	VectorBool::BoolReference::changeBit(const bool &bit)
{
	if (bit)
        _character |= (1u << (_index % 8)); // Set the bit to 1
    else
        _character &= ~(1u << (_index % 8)); // Set the bit to 0
    _bit = bit;
}

VectorBool::BoolReference	&VectorBool::BoolReference::operator =(const bool &bit)
{
	changeBit(bit);
	return (*this);
}

# include "VectorBool.hpp"

#endif

// class reference
// {
// 	public:
// 		reference(size_t *ptr, size_t index);
// 		reference(const reference &obj);
// 		reference operator= (bool flag);
// 		reference operator= (const reference &obj);
// 		reference operatorbool (void);
//		reference &operator[] (size_t index); HERE?! i think no
// 	private:
// 		size_t	*ptr;
// 		size_t	index;
// 		bool	flag;
// };

// VectorBool::reference VectorBool::operator[] (size_t index)
// {
// 		return (VectorBool::reference(m_ptr, index));
// }

// flag = ptr(index/BITCOUNT) & (1 << index % BITCOUNT);

// bool VectorBool::reference::operatorbool (void)
// {
// 		return (this->flag);
// }