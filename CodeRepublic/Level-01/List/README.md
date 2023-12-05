# List Class Implementation

The given task is to implement a class in C++ which behaves just like the std::list class.

| Function       | Description                                    | Syntax                      |
|----------------|------------------------------------------------|-----------------------------|
| Modifiers      |                                                |                             |
| clear          | Clears the contents                            | `void clear();`             |
| insert         | Inserts elements                               | `iterator insert(iterator pos, const T& value);` |
| insert_range   | Inserts a range of elements (C++23)            | `void insert_range(iterator pos, InputIt first, InputIt last);` |
| emplace        | Constructs element in-place (C++11)            | `iterator emplace(iterator pos, Args&&... args);` |
| erase          | Erases elements                                | `iterator erase(iterator pos);` |
| push_back      | Adds an element to the end                     | `void push_back(const T& value);` |
| emplace_back   | Constructs an element in-place at the end (C++11) | `void emplace_back(Args&&... args);` |
| append_range   | Adds a range of elements to the end (C++23)    | `void append_range(InputIt first, InputIt last);` |
| pop_back       | Removes the last element                       | `void pop_back();`           |
| push_front     | Inserts an element to the beginning            | `void push_front(const T& value);` |
| emplace_front  | Constructs an element in-place at the beginning (C++11) | `void emplace_front(Args&&... args);` |
| prepend_range  | Adds a range of elements to the beginning (C++23) | `void prepend_range(InputIt first, InputIt last);` |
| pop_front      | Removes the first element                      | `void pop_front();`          |
| resize         | Changes the number of elements stored          | `void resize(size_type count);` |
| swap           | Swaps the contents                             | `void swap(List& other);`    |
| Operations     |                                                |                             |
| merge          | Merges two sorted lists                        | `void merge(List& other);`   |
| splice         | Moves elements from another list               | `void splice(iterator pos, List& other);` |
| remove         | Removes elements satisfying specific criteria  | `void remove(const T& value);` |
| remove_if      | Removes elements satisfying specific criteria  | `void remove_if(Predicate pred);` |
| reverse        | Reverses the order of the elements             | `void reverse();`            |
| unique         | Removes consecutive duplicate elements         | `void unique();`             |
| sort           | Sorts the elements                             | `void sort();`               |
| Non-member functions |                                         |                             |
| operator==     | Checks equality between two lists              | `bool operator==(const List& lhs, const List& rhs);` |
| operator!=     | Checks inequality between two lists            | `bool operator!=(const List& lhs, const List& rhs);` |
| operator<      | Checks if one list is less than another        | `bool operator<(const List& lhs, const List& rhs);` |
| operator<=     | Checks if one list is less than or equal to another | `bool operator<=(const List& lhs, const List& rhs);` |
| operator>      | Checks if one list is greater than another     | `bool operator>(const List& lhs, const List& rhs);` |
| operator>=     | Checks if one list is greater than or equal to another | `bool operator>=(const List& lhs, const List& rhs);` |
