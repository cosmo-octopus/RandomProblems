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
				unsigned char	_reference;
				size_t			_bit;
				// bool			flag;

			public:
				BoolReference(unsigned char &character, size_t	bit);
				~BoolReference();

				bool	getBit(void);
		};

		size_t	get_size(void) const;
		size_t	max_size(void) const;
		void	push_back(bool value);
		void	pop_back(void);
		bool	at(size_t index) const;
		bool	At(size_t index);
		void	reserve(size_t capacity);
		void	print(void);
		void	resize(size_t size);
};

VectorBool::BoolReference::BoolReference(unsigned char &character, size_t bit): _reference(character), _bit(bit)
{
}

VectorBool::BoolReference::~BoolReference()
{
}

bool	VectorBool::BoolReference::getBit(void)
{
	int	musk = (1 << this->_bit);
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