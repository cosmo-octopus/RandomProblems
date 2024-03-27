#include "Cell.hpp"

/* ctors */
Cell::Cell() : line("_") {}

Cell::Cell(const Cell& rhs) { line = rhs.line; }

Cell::Cell(const std::string& str) : line(str) {}

Cell::Cell(int val) : line(std::to_string(val)) {}

Cell::Cell(double val) : line(std::to_string(val)) {}



Cell&	Cell::operator=(const Cell& rhs)
{
	if (this != &rhs)
		line = rhs.line;
	return *this;
}

Cell&	Cell::operator=(const std::string& str)
{
	if (&line != &str)
		line = str;
	return *this;
}

Cell&	Cell::operator=(int val)
{
	line = std::to_string(val);
	return *this;
}

Cell&	Cell::operator=(double val)
{
	line = std::to_string(val);
	return *this;
}

int	Cell::to_int()
{
	int res = 0;

	try {
		res = std::stoi(line);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return res;
}

double	Cell::to_double()
{
	double res = 0;

	try {
		res = std::stod(line);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return res;
}

std::string	Cell::to_string()
{
	return line;
}

std::ostream&	operator<<(std::ostream& os, const Cell& cell)
{
	std::cout << cell.line;
	return os;
}