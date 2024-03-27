#ifndef CELL_HPP
# define CELL_HPP

# include <iostream>
# include <string>
# include <exception>

class Cell {
	private:
		std::string	line;
	public:
		Cell();
		Cell(const Cell& rhs);
		Cell(const std::string& str);
		Cell(int val);
		Cell(double val);
		~Cell() = default;

		Cell&	operator=(const Cell& rhs);
		Cell&	operator=(const std::string& str);
		Cell&	operator=(int val);
		Cell&	operator=(double val);

		friend std::ostream& \
		operator<<(std::ostream& os, const Cell& cell);

		int			to_int();
		double		to_double();
		std::string	to_string();
};

#endif