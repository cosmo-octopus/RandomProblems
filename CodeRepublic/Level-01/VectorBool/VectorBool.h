#ifndef __VECTORBOOL_H__
# define __VECTORBOOL_H__

# include <limits>
# include <utility>
# include <iostream>
# include <stdexcept>

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

		size_t	get_size(void) const;
		size_t	max_size(void) const;
		void	reserve(size_t capacity);
		void	push_back(bool value);
		void	pop_back(void);
		bool	at(size_t index) const;

};

# include "VectorBool.hpp"

#endif