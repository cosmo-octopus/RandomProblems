#ifndef __VECTORBOOL_HPP__
# define __VECTORBOOL_HPP__

// # include "VectorBool.h"

VectorBool::VectorBool(void): _data(nullptr), _size(0), _capacity(0)
{
}

VectorBool::~VectorBool()
{
	delete[] _data;
}

#endif