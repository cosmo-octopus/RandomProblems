#ifndef __BOOLREFERENCE_HPP__
# define __BOOLREFERENCE_HPP__

# include "VectorBool.h"

VectorBool::BoolReference::BoolReference(unsigned char &character, size_t index): _character(character), _index(index), _bit(0)
{
	_bit = (character >> (index % 8)) & 1;
}

VectorBool::BoolReference::BoolReference(unsigned char &character, size_t index, const bool &bit): _character(character), _index(index), _bit(bit)
{
	if (bit)
        _character |= (1u << (_index % 8)); // Set the bit to 1
    else
        _character &= ~(1u << (_index % 8)); // Set the bit to 0
    _bit = bit;
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

#endif