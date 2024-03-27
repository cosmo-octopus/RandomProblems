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
		int	row;
		int	col;
	public:
		SpreadSheet() = delete;
		SpreadSheet(int row, int col);
		~SpreadSheet();

		Cell&	operator()(int row, int col);

		friend std::ostream& \
		operator<<(std::ostream& os, const SpreadSheet& sp);

		void	addRow(int row);
		void	addCol(int col);
		void	resizeRow(int size);
		void	resizeCol(int size);
		void	resize(int row, int col);

		int	height();
		int	width();
};

#endif