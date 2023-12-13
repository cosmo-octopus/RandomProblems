# List Class Implementation

The given task is to implement a class in C++ which behaves just like the std::list class.

| Function       | Description                                    | Syntax                      |
|----------------|------------------------------------------------|-----------------------------|
| Modifiers      |                                                |                             |
| clear          | Clears the contents                            | `void clear();`             |
| insert         | Inserts elements                               | `iterator insert(iterator pos, const T& value);` |
| erase          | Erases elements                                | `iterator erase(iterator pos);` |
| push_back      | Adds an element to the end                     | `void push_back(const T& value);` |
| pop_back       | Removes the last element                       | `void pop_back();`           |
| push_front     | Inserts an element to the beginning            | `void push_front(const T& value);` |
| pop_front      | Removes the first element                      | `void pop_front();`          |
| swap           | Swaps the contents                             | `void swap(List& other);`    |
| Operations     |                                                |                             |
| merge          | Merges two sorted lists                        | `void merge(List& other);`   |
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
