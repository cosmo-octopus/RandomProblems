#ifndef CELL_HPP
# define CELL_HPP

# include <iostream>
# include <vector>
# include <string>
# include <exception>

class Cell {
	private:
		std::string	line;
	public:
		/* CONSTRUCTORS */
		Cell();
		Cell(const Cell& rhs);
		Cell(const std::string& str);
		Cell(int val);
		Cell(double val);
		~Cell() = default;

		/* ASSIGNMENT OPERATOR */
		const Cell&	operator=(const Cell& rhs);
		const Cell& operator=(Cell&& rhs);
		const Cell&	operator=(const std::string& str);
		const Cell&	operator=(int val);
		const Cell&	operator=(double val);
		const Cell& operator=(char val);  
		const Cell& operator=(bool val);
		const Cell& operator=(const std::vector<int>& rhs);

		operator int();  
		operator double();  
		operator char();  
		operator bool();  
		operator std::string();  
		operator std::vector<int>(); 

		/* GETTERS */
		const std::string&	getLine() const;

		/* SETTERS */
		void	setLine(const std::string& input);

		/* MANIPULATIONS */
		int			to_int();
		double		to_double();
		std::string	to_string();
};

bool	operator==(const Cell& lhs, const Cell& rhs);
bool	operator!=(const Cell& lhs, const Cell& rhs);

std::ostream&	operator<<(std::ostream& out, const Cell& cell);
std::istream&	operator>>(std::istream& in, Cell& cell);


#endif