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

				operator bool();
				BoolReference	&operator= (const bool &bit);

				bool			getBit(void);
				void			changeBit(const bool &bit);
		};

		size_t						get_size(void) const;
		size_t						max_size(void) const;
		void						push_back(bool value);
		void						pop_back(void);
		void						reserve(size_t capacity);
		void						print(void);
		void						resize(size_t size);
		void						operator =(bool flag);
		VectorBool::BoolReference	at(size_t index);
		friend std::ostream			&operator<<(std::ostream &os, VectorBool &obj);

};

# include "BoolReference.hpp"
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