#include "SpreadSheet.hpp"

SpreadSheet::Column::Column(Cell* col) : col(col) {}

Cell& SpreadSheet::Column::operator[](size_t pos)
{
	return col[pos];
}

const Cell& SpreadSheet::Column::operator[](size_t pos) const
{
	return col[pos];
}