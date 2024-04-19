#include <iostream>
#include "SpreadSheet.hpp"
#include "Cell.hpp"

int main()
{
    SpreadSheet ob(5, 5);

    for (int i = 0; i < ob.height(); ++i) {
        for (int j = 0; j < ob.width(); ++j) {
            ob[i][j] = Cell("AAAAAAAAAAA");
        }
    }

    std::cout << ob << std::endl;

    ob.resizeRow(7);
    ob.resizeCol(13);


    for (int i = 0; i < ob.height(); ++i) {
        for (int j = 0; j < ob.width(); ++j) {
            if (ob[i][j].to_string().empty()) {
                continue;
            }
            int z = i + j % 4;
            
            switch (z) {
                case 0: {
                    ob[i][j] = i * j;
                    break;
                }
                case 1: {
                    ob[i][j] = std::to_string(i + j);
                    break;
                }
                case 2: {
                    ob[i][j] = i * 1.2 / j;
                    break;
                }
                case 3: {
                    ob[i][j] = std::vector<int>(i, j);
                    break;
                }
            }    
        }
    }

    std::cout << ob << std::endl;

    ob.resize(11, 13);

    std::cout << ob << std::endl;

    ob.mirrorH();
    ob.mirrorV();

    std::cout << ob << std::endl;

	ob.resize(10,10);

    SpreadSheet ob2 = ob;

    ob.mirrorD();
    ob2.mirrorSD();

	std::cout << ob << std::endl;
	std::cout << ob2 << std::endl;

    std::vector<int> v1 = ob[8][7];
    std::vector<int> v2 = ob2[0][0];

    std::cout << std::boolalpha << v1.empty() << std::endl;

	for (auto it = v1.begin(); it != v1.end(); ++it)
		std::cout << *it;
	std::cout << std::endl;

    std::cout << std::boolalpha << v2.empty() << std::endl;

    std::cout << std::boolalpha << (v1 == v2) << std::endl;

	ob2.rotate(1);
	std::cout << ob2 << std::endl;

    return 0;
}