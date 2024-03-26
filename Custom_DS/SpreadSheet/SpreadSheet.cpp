#include "SpreadSheet.hpp"

SpreadSheet::SpreadSheet(int row, int col)
{
	if (row < 1 || col < 1)
		throw std::invalid_argument("Minimum size: 1x1");

	mat = new Cell* [row];
	for (size_t i = 0; i < row; ++i)
		mat[i] = new Cell[col];

	this->row = row;
	this->col = col;
}

SpreadSheet::~SpreadSheet()
{
	for (size_t i = 0; i < row; ++i)
		delete[] mat[i];
	delete[] mat;
}

void	SpreadSheet::addRow(size_t row)
{
	if (row < 1)
		throw std::invalid_argument("Invalid argument");
	
	Cell**	m = new Cell* [this->row + row];
	for (size_t i = 0; i < this->row + row; ++i)
	{
		if (i < this->row)
			m[i] = mat[i];
		else
			m[i] = new Cell[col];
	}
	delete[] mat;
	mat = m;
	this->row += row;
}

void	SpreadSheet::addCol(size_t col)
{
	if (col < 1)
		throw std::invalid_argument("Invalid argument");

	for (size_t i = 0; i < this->row; ++i)
	{
		Cell* tmp = new Cell[this->col + col];
		for (size_t j = 0; j < this->col + col; ++j)
		{
			if (j < this->col)
				tmp[j] = mat[i][j];
			else
				tmp[j] = Cell();
		}
		delete[] mat[i];
		mat[i] = tmp;
	}
		this->col += col;
}