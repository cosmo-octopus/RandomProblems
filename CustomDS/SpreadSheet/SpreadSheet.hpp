#ifndef SPREADSHEET_HPP
# define SPREADSHEET_HPP

# include <iostream>
# include <vector>
# include <string>
# include <exception>

# include "Cell.hpp"

class Cell;

class SpreadSheet {
	private:
		Cell**	mat;
		int	row;
		int	col;
	private:
		class	Column;
	public:
		SpreadSheet() = delete;
		SpreadSheet(int row, int col);
		SpreadSheet(int size);
		SpreadSheet(const SpreadSheet& rhs);
		SpreadSheet(SpreadSheet&& rhs);
		~SpreadSheet();

		const SpreadSheet&	operator=(const SpreadSheet& rhs);
		const SpreadSheet&	operator=(SpreadSheet&& rhs);
		Column				operator[](size_t pos);
		const Column		operator[](size_t pos) const;
		Cell&				operator()(int row, int col);

		friend std::ostream& \
		operator<<(std::ostream& os, const SpreadSheet& sp);

		void	addRow(int row);
		void	addCol(int col);
		void	removeRow(int row);
		void	removeRows(std::initializer_list<int> rows);
		void	removeCol(int col);
		void	removeCols(std::initializer_list<int> cols);
		void	resizeRow(int size);
		void	resizeCol(int size);
		void	resize(int row, int col);

		int				height() const;
		int				width() const;
		Cell**	getMat() const { return mat; }

		void mirrorH();
		void mirrorV();
		void mirrorD();
		void mirrorSD();

		void rotate(int cnt);

		void clear() noexcept;

		SpreadSheet slice(std::initializer_list<int> rows, std::initializer_list<int> cols);
};

class SpreadSheet::Column {
	private:
		Cell* col;
	public:
		explicit Column(Cell* col);
	public:
		Column() = delete;
		Column(const Column&) = delete;
		Column(Column&&) = delete;

		const Column& operator=(const Column&) = delete;
		const Column& operator=(Column&&) = delete;
	public:
		Cell&		operator[](size_t pos);
		const Cell&	operator[](size_t pos) const;
};

bool operator==(const SpreadSheet& lhs, const SpreadSheet& rhs);
bool operator!=(const SpreadSheet& lhs, const SpreadSheet& rhs);

#endif