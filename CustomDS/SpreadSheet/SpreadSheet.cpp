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

SpreadSheet::SpreadSheet(const SpreadSheet& rhs) : row(rhs.row), col(rhs.col)
{
    mat = new Cell*[row];
    for (int i = 0; i < row; ++i) {
		mat[i] = new Cell[col];
        for (int j = 0; j < col; ++j) {
            mat[i][j] = rhs.mat[i][j];
        }
    }
}

SpreadSheet::SpreadSheet(SpreadSheet&& rhs)
{

	mat = std::move(rhs.mat);
	row = rhs.row;
	col = rhs.col;

	rhs.row = 0;
	rhs.col = 0;
}

SpreadSheet::SpreadSheet(int size)
{
	SpreadSheet(size, size);
}

SpreadSheet::~SpreadSheet()
{
	if (row && col)
		clear();
}

const SpreadSheet&	SpreadSheet::operator= (const SpreadSheet& rhs)
{
	if (this != &rhs)
	{
		if (mat && *mat)
		{
			for (int i = 0; i < row; ++i)
				delete [] mat[i];
			delete [] mat;
		}

		mat = new Cell*[rhs.row];
		for (int i = 0; i < rhs.row; ++i)
		{
			mat[i] = new Cell[rhs.col];
			for (int j = 0; j < rhs.col; ++j)
				mat[i][j] = rhs.mat[i][j];
		}
		row = rhs.row;
		col = rhs.col;
	}
	return *this;
}

const SpreadSheet&	SpreadSheet::operator= (SpreadSheet&& rhs)
{
	if (this != &rhs)
	{
		if (mat && *mat)
		{
			for (int i = 0; i < row; ++i)
				delete [] mat[i];
			delete [] mat;
		}

		mat = rhs.mat;
		row = rhs.row;
		col = rhs.col;

		rhs.mat = nullptr;
		rhs.row = 0;
		rhs.col = 0;
	}
	return *this;
}

SpreadSheet::Column SpreadSheet::operator[](size_t pos)
{
	return Column(mat[pos]);
}

const SpreadSheet::Column SpreadSheet::operator[](size_t pos) const
{
	return Column(mat[pos]);
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

void	SpreadSheet::removeRow(int row)
{
	if (row >= this->row)
		throw std::out_of_range("Row index out of range");

	delete[] mat[row];
	for (int i = row; i < this->row - 1; ++row)
		mat[i] = mat[i + 1];
	this->row--;
}

void SpreadSheet::removeRows(std::initializer_list<int> rows)
{
	for (int row : rows)
		removeRow(row);
}

void SpreadSheet::removeCol(int col)
{
    if (col >= this->col)
		throw std::out_of_range("Column index out of range");

    for (int i = 0; i < this->row; ++i)
	{
        for (int j = col; j < this->col - 1; ++j)
            mat[i][j] = mat[i][j + 1];
	}

	this->col--;
}

void SpreadSheet::removeCols(std::initializer_list<int> cols)
{
	for (int col : cols)
		removeCol(col);
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

int	SpreadSheet::height() const
{
	return row;
}

int	SpreadSheet::width() const
{
	return col;
}

void SpreadSheet::mirrorH()
{
    for (int i = 0; i < this->row; ++i)
    {
        for (int j = 0; j < this->col / 2; ++j)
        {
            std::swap(mat[i][j], mat[i][this->col - j - 1]);
        }
    }
}

void SpreadSheet::mirrorV()
{
    for (int i = 0; i < this->row / 2; ++i)
    {
        for (int j = 0; j < this->col; ++j)
        {
            std::swap(mat[i][j], mat[this->row - i - 1][j]);
        }
    }
}

void SpreadSheet::mirrorD()
{
	if (this->row != this->col)
        throw std::logic_error("Cannot perform diagonal mirror on non-square spreadsheet");

    for (int i = 0; i < this->row; ++i)
        for (int j = i + 1; j < this->col; ++j)
            std::swap(mat[i][j], mat[j][i]);
}

void SpreadSheet::mirrorSD()
{
    if (this->row != this->col)
        throw std::logic_error("Cannot perform secondary diagonal mirror on non-square spreadsheet");

    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < this->row - i - 1; ++j)
            std::swap(mat[i][j], mat[this->row - j - 1][this->col - i - 1]);
}

void	SpreadSheet::clear() noexcept
{
	if (row && col)
	{
		for (int i = 0; i < row; ++i)
			delete[] mat[i];
		delete[] mat;
	}
	row = 0;
	col = 0;
}

void SpreadSheet::rotate(int cnt)
{
    cnt %= 4;

    for (int k = 0; k < cnt; ++k)
    {
		Cell** newmat = new Cell*[this->col];

        for (int i = 0; i < this->col; ++i)
        {
			newmat[i] = new Cell[this->row];
			for (int j = 0; j < this->row; ++j)
				newmat[i][j] = mat[this->row - j - 1][i];
        }

        for (int i = 0; i < this->row; ++i)
        {
            delete[] mat[i];
        }
        delete[] mat;

		mat = newmat;
		std::swap(this->row, this->col);
    }
}

bool operator==(const SpreadSheet& lhs, const SpreadSheet& rhs)
{
	if (lhs.height() != rhs.height() || lhs.width() != rhs.width())
    {
        return false;
    }

    for (int i = 0; i < lhs.height(); ++i)
    {
        for (int j = 0; j < lhs.width(); ++j)
        {
            if (lhs.getMat()[i][j] != rhs.getMat()[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(const SpreadSheet& lhs, const SpreadSheet& rhs)
{
    return !(lhs == rhs);
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
