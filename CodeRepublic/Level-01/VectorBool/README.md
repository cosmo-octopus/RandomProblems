# `std::vector<bool>`

`std::vector<bool>` is a possibly space-efficient specialization of std::vector for the type bool.

The manner in which std::vector<bool> is made space efficient (as well as whether it is optimized at all) is implementation defined. One potential optimization involves coalescing vector elements such that `each element occupies a single bit` instead of sizeof(bool) bytes.

`std::vector<bool>` behaves similarly to std::vector, but in order to be space efficient, it:

- Does not necessarily store its elements as a contiguous array.
- Exposes class std::vector<bool>::reference as a method of accessing individual bits. In particular, objects of this class are returned by operator[] by value.
- Does not use std::allocator_traits::construct to construct bit values.
- Does not guarantee that different elements in the same container can be modified concurrently by different threads.