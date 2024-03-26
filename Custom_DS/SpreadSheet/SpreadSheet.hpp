#ifndef SPREADSHEET_HPP
# define SPREADSHEET_HPP

# include <iostream>
# include <vector>
# include <string>
# include <exception>

# include "Cell.hpp"

class SpreadSheet {
	private:
		Cell**	mat;
		size_t	row;
		size_t	col;
	public:
		SpreadSheet() = delete;
		SpreadSheet(int row, int col);
		~SpreadSheet();

		void	addRow(size_t row);
		void	addCol(size_t col);
		void	resizeRow(size_t size);
		void	resizeCol(size_t size);
		void	resize(size_t row, size_t col);

		size_t	height();
		size_t	width();
};

#endif