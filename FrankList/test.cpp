#include <iostream>
#include <cassert>
#include "FrankList.hpp"

using namespace vhuk;

int main() {
    FrankList<int> list;

    // Test push_back and front
    list.push_back(1);
    list.push_back(2);
    std::cout << "Test: push_back and front - ";
    assert(list.front() == 1);
    std::cout << "Passed" << std::endl;

    // Test push_front and back
    list.push_front(0);
    std::cout << "Test: push_front and back - ";
    assert(list.back() == 2);
    std::cout << "Passed" << std::endl;

    // Test size
    std::cout << "Test: size - ";
    assert(list.size() == 3);
    std::cout << "Passed" << std::endl;

    // Test insert
    FrankList<int>::iterator it = list.begin();
    it++;
    list.insert(it, 5);
    std::cout << "Test: insert - ";
    assert(list.size() == 4);
    assert(*(--it) == 5);
    std::cout << "Passed" << std::endl;
    list.print();

    // Test erase
    it = list.begin();
    ++it;
    ++it;
    list.erase(it);
    std::cout << "Test: erase - ";
    assert(list.size() == 3);
    std::cout << "Passed" << std::endl;
    list.print();

    // Test sort
    std::cout << "Test: sort - ";
    list.sort();
    std::cout << "Passed" << std::endl;
    list.print();
    assert(list.front() == 0);
    assert(list.back() == 5);

    // Test reverse
    std::cout << "Test: reverse - ";
    list.reverse();
    std::cout << "Passed" << std::endl;
    assert(list.front() == 5);
    assert(list.back() == 0);

    // Test find
    it = list.find(2);
    std::cout << "Test: find - ";
    assert(it != list.end());
    assert(*it == 2);
    std::cout << "Passed" << std::endl;

    // Test remove
    std::cout << "Test: remove - ";
    list.remove(2);
    std::cout << "Passed" << std::endl;
    assert(list.size() == 2);
    assert(list.back() != 2);
    list.print();

    // Test traversal
    std::cout << "Test: traversal - Traversal: ";
    list.traverse([](int val) { std::cout << val + 1 << " "; });
    std::cout << std::endl;

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

