#ifndef __PAIR_HPP__
# define __PAIR_HPP__

# include "Pair.h"

template <typename T1, typename T2>
T1	Pair<T1, T2>::getFirst(void) const
{
	return (this->first);
}

template <typename T1, typename T2>
T2	Pair<T1, T2>::getSecond(void) const
{
	return (this->second);
}

template <typename T1, typename T2>
void	Pair<T1, T2>::setFirst(const T1 &value)
{
	this->first = value;
}

template <typename T1, typename T2>
void	Pair<T1, T2>::setSecond(const T2 &value)
{
	this->second = value;
}

template <typename T1, typename T2>
void	Pair<T1, T2>::print(void) const
{
	std::cout << "[ " << this->first << ", " << this->second << " ]" << std::endl; 
}

template <typename T1, typename T2>
void	swap(Pair<T1, T2> &a, Pair<T1, T2> &b)
{
	using std::swap;
	swap(a.first, b.first);
	swap(a.second, b.second);
}

template <typename T1, typename T2>
bool operator==(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
    return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

template <typename T1, typename T2>
bool operator!=(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
    return !(lhs == rhs);
}

template <typename T1, typename T2>
bool operator<(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
    if (lhs.first != rhs.first)
        return (lhs.first < rhs.first);
    return (lhs.second < rhs.second);
}

template <typename T1, typename T2>
Pair<T1, T2>	make_pair(T1 x, T2 y)
{
	return (Pair(x, y));
}

#endif