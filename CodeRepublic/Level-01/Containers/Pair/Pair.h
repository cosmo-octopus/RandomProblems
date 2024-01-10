# ifndef __PAIR_H__
# define __PAIR_H__

# include <iostream>
# include <utility>

template <typename T1, typename T2>
class	Pair
{
	private:
		T1	first;
		T2	second;

	public:
		Pair(void): first(0), second(0) {}
		Pair(const T1 &f, const T2 &s): first(f), second(s){}

		T1			getFirst(void) const;
		T2			getSecond(void) const;
		void		setFirst(const T1 &value);
		void		setSecond(const T2 &value);
		void		print(void) const;

		template <typename U1, typename U2>
		friend Pair	make_pair(U1 x, U2 y);

		/* Non-member function overloads */
		template <typename U1, typename U2>
		friend void swap(Pair<U1, U2>& a, Pair<U1, U2>& b);

		template <typename U1, typename U2>
		friend bool operator==(const Pair<U1, U2>& lhs, const Pair<U1, U2>& rhs);

		template <typename U1, typename U2>
		friend bool operator!=(const Pair<U1, U2>& lhs, const Pair<U1, U2>& rhs);

		template <typename U1, typename U2>
		friend bool operator<(const Pair<U1, U2>& lhs, const Pair<U1, U2>& rhs);
};

# include "Pair.hpp"

#endif