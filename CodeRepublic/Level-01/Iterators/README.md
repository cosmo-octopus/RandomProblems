# Iterators

Iterators in C++ are objects that provide a way to iterate through the elements of a container or a sequence of elements. They act as a generalized pointer that points to an element within the container and can be used to traverse the elements, access values, and perform various operations on the elements.

In C++, iterators are classified into five main types based on their functionalities:

- `Input Iterators`: These iterators allow sequential access to read the elements in a forward direction. They support operations like dereferencing (*it), post-increment (it++), pre-increment (++it), and equality/inequality comparisons (it == it2, it != it2). Input iterators provide the minimum functionality required to read values from a container but don't guarantee the ability to modify elements or perform random access.

- `Output Iterators`: These iterators allow sequential access for writing elements into a container in a forward direction. They support operations similar to input iterators but for writing values to a container. They are used to perform output operations and have limited capabilities compared to other iterator types.

 - `Forward Iterators`: Forward iterators are an extension of input iterators and provide the ability to read and write elements in a single pass through a sequence. They support all the operations of input iterators, as well as multiple passes to the same element and modification of elements during iteration.

- `Bidirectional Iterators`: Bidirectional iterators enhance the functionality of forward iterators by adding the capability to move backward through a sequence. They support all the operations of forward iterators along with the ability to perform pre-decrement (--it) and post-decrement (it--) operations.

- `Random Access Iterators`: These iterators provide the most functionality among the iterator types. They support all the functionalities of bidirectional iterators and also enable random access to elements within the container. Random access iterators allow operations like addition (it + n), subtraction (it - n), comparison (<, <=, >, >=), and indexing (it[n]).
