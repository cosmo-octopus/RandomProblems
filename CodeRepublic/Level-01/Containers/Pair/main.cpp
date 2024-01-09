#include "Pair.h"

int	main()
{
    Pair<int, double>	pair1(42, 3.14);
    Pair<int, double>	pair2(10, 5.0);

    /* Testing getters and setters */
    std::cout << "Initial values:" << std::endl;
    std::cout << "First: " << pair1.getFirst() << ", Second: " << pair1.getSecond() << std::endl;

    pair1.setFirst(99);
    pair1.setSecond(6.28);

    std::cout << "Values after modification:" << std::endl;
    std::cout << "First: " << pair1.getFirst() << ", Second: " << pair1.getSecond() << std::endl;

    /* Testing relational operators */
    std::cout << "Comparing pairs:" << std::endl;
    if (pair1 == pair2)
        std::cout << "pair1 and pair2 are equal." << std::endl;
    else
        std::cout << "pair1 and pair2 are not equal." << std::endl;

    if (pair1 != pair2)
        std::cout << "pair1 and pair2 are not equal." << std::endl;
    else
        std::cout << "pair1 and pair2 are equal." << std::endl;

    if (pair1 < pair2)
        std::cout << "pair1 is less than pair2." << std::endl;
    else
        std::cout << "pair1 is not less than pair2." << std::endl;

    /* Testing swap function */
    std::cout << "Before swapping:" << std::endl;
    std::cout << "First pair: " << pair1.getFirst() << ", " << pair1.getSecond() << std::endl;
    std::cout << "Second pair: " << pair2.getFirst() << ", " << pair2.getSecond() << std::endl;

    swap(pair1, pair2);

    std::cout << "After swapping:" << std::endl;
    std::cout << "First pair: " << pair1.getFirst() << ", " << pair1.getSecond() << std::endl;
    std::cout << "Second pair: " << pair2.getFirst() << ", " << pair2.getSecond() << std::endl;
}
