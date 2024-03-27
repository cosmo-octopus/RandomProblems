#include "SpreadSheet.hpp"

SpreadSheet::SpreadSheet(int row, int col)
{
	if (row < 1 || col < 1)
		throw std::invalid_argument("Minimum size: 1x1");

	mat = new Cell* [row];
	for (int i = 0; i < row; ++i)
		mat[i] = new Cell[col];

	this->row = row;
	this->col = col;
}

SpreadSheet::~SpreadSheet()
{
	for (int i = 0; i < row; ++i)
		delete[] mat[i];
	delete[] mat;
}

Cell&	SpreadSheet::operator()(int row, int col)
{
	if (row < 0 || row > this->row || col < 0 || col > this->col)
		throw std::out_of_range("Invalid index");
	return static_cast<Cell&>(mat[row][col]);
}

void	SpreadSheet::addRow(int row)
{
	if (row < 1)
		throw std::invalid_argument("Invalid argument");
	
	Cell**	m = new Cell* [this->row + row];
	for (int i = 0; i < this->row + row; ++i)
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

void	SpreadSheet::addCol(int col)
{
	if (col < 1)
		throw std::invalid_argument("Invalid argument");

	for (int i = 0; i < this->row; ++i)
	{
		Cell* tmp = new Cell[this->col + col];
		for (int j = 0; j < this->col + col; ++j)
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

void	SpreadSheet::resizeRow(int size)
{
	if (size < 1)
		throw std::invalid_argument("You're attempting to delete the table");
	if (size > row)
		addRow(size - row);
	else
	{
		for (int i = size; i < row; ++i)
			delete[] mat[i];
		row = size;
	}
}

void	SpreadSheet::resizeCol(int size)
{
	if (size < 1)
		throw std::invalid_argument("You're attempting to delete the table");
	if (size > col)
		addCol(size - col);
	else
		col = size;
}

void	SpreadSheet::resize(int row, int col)
{
	resizeRow(row);
	resizeCol(col);
}

int	SpreadSheet::height()
{
	return row;
}

int	SpreadSheet::width()
{
	return col;
}

std::ostream&	operator<<(std::ostream& os, const SpreadSheet& sp)
{
	for (int i = 0; i < sp.row; ++i)
	{
		for (int j = 0; j < sp.col; ++j)
		{
			os << "[ ";
			os << sp.mat[i][j];
			os << " ] ";

		}
		os << std::endl;
	}
	return os;
}