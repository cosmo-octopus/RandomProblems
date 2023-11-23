#ifndef __VECTORBOOL_H__
# define __VECTORBOOL_H__

# include <limits>
# include <utility>
# include <iostream>
# include <stdexcept>

class	VectorBool
{
	private:
		unsigned char*				_data;
		size_t						_size;
		size_t						_capacity;
		// static const unsigned char	_bit_mask;
	public:
		VectorBool(void);
		~VectorBool();
};

# include "VectorBool.hpp" 

#endif