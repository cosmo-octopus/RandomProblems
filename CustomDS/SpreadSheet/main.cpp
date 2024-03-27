#include <iostream>
#include "SpreadSheet.hpp"

int main()
{
	SpreadSheet table(4, 5);

	table(0, 0) = "hello";
	table(1, 1) = 4.42;
	table(2, 2) = 7;

	std::cout << table << "\n";

	table.addRow(3);

	table(6, 1) = "3.14";

	std::cout << table << "\n";

	table.addCol(3);

	table(6, 7) = "marvin";

	std::cout << table << std::endl;

	table.resizeRow(3);

	std::cout << table << std::endl;

	table.resizeRow(10);
	table.resizeCol(3);

	std::cout << table << std::endl;

	table.resize(4, 4);

	std::cout << table << std::endl;


	return 0;
}