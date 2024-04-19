#include "Cell.hpp"

/* ctors */
Cell::Cell() : line("_") {}

Cell::Cell(const Cell& rhs) { line = rhs.line; }

Cell::Cell(const std::string& str) : line(str) {}

Cell::Cell(int val) : line(std::to_string(val)) {}

Cell::Cell(double val) : line(std::to_string(val)) {}


const Cell&	Cell::operator=(const Cell& rhs)
{
	if (this != &rhs && !rhs.line.empty())
	{
		line = rhs.line;
	}
	return *this;
}

const Cell&	Cell::operator= (Cell&& rhs)
{
	if (this != &rhs)
	{
		line = std::move(rhs.line);
		rhs.line.clear();
	}
	return *this;
}

const Cell&	Cell::operator=(const std::string& str)
{
	if (&line != &str)
		line = str;
	return *this;
}

const Cell&	Cell::operator=(int val)
{
	line = std::to_string(val);
	return *this;
}

const Cell&	Cell::operator=(double val)
{
	line = std::to_string(val);
	return *this;
}

const Cell&	Cell::operator= (char val)
{
	line = val;
	return *this;
}

const Cell&	Cell::operator= (bool val)
{
	line = val ? "true" : "false";
	return *this;
}

const Cell&	Cell::operator=(const std::vector<int>& rhs)
{
	std::string	str;

	for (int i : rhs)
		str += std::to_string(i);
	line = std::move(str);
	return *this;
}

const std::string&	Cell::getLine() const
{
	return line;
}

void	Cell::setLine(const std::string& input)
{
	line = input;
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

bool operator==(const Cell& lhs, const Cell& rhs)
{
    return lhs.getLine()== rhs.getLine();
}

bool operator!=(const Cell& lhs, const Cell& rhs)
{
    return !(lhs == rhs);
}

std::ostream&	operator<<(std::ostream& os, const Cell& cell)
{
	std::cout << cell.getLine();
	return os;
}

std::istream&	operator>>(std::istream& in, Cell& cell)
{
	std::string input;
	in >> input;
	cell.setLine(input);
	return in;
}

Cell::operator int()
{
    return to_int();
}

Cell::operator double()
{
    return to_double();
}

Cell::operator char()
{
    std::string str = to_string();
    if (str.length() > 0)
        return str[0];
    return '\0';
}

Cell::operator bool()
{
    std::string str = to_string();
    return str == "true" || str == "1";
}

Cell::operator std::string()
{
    return to_string();
}

Cell::operator std::vector<int>()
{
    std::string str = to_string();
    std::vector<int> vec;
    for (char c : str)
    {
        if (isdigit(c))
            vec.push_back(c - '0');
    }
    return vec;
}