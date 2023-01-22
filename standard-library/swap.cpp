// Possible implementation of std::swap (simplified):
// template<typename T>
// inline auto swap(T& x, T& y) noexcept {
//     T tmp{std::move(x)};
//     x = std::move(y);
//     y = std::move(tmp);
// }
// Can be even improved with concept library

// To implement a copy assignment or move assignment operator or a move
// constructor we use the Copy-and-Swap Idiom.
// (Often harmful to performance when strong exception safety guarantee is not
// needed from copy assignment, which could be provided by a short generic
// function in addition to a much faster copy assignment operator.)
// Example:
// class CopyAndSwap {
//     // Special member methods and data members
//     // Copy constructor as always
// };
//
// CopyAndSwap::swap(CopyAndSwap& other) noexcept {
//     using std::swap;
//     // Swap each data member, e.g. swap(m_data, other.m_data);
// }
//
// CopyAndSwap& CopyAndSwap::operator=(const CopyAndSwap& rhs) {
//     auto copy{rhs};
//     swap(copy);
//     return *this;
// }
//
// CopyAndSwap::CopyAndSwap(CopyAndSwap&& src) noexcept {
//     swap(*this, src);
// }
//
// CopyAndSwap& operator=(CopyAndSwap&& rhs) noexcept {
//     swap(*this, rhs);
//     return *this;
// }
//
// Implement also a standalone noexcept swap function:
// void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept {
//     first.swap(second);
// }

import <algorithm>;
import <experimental/iterator>;
import <iostream>;
import <utility>;

auto printIntVector(auto vec) {
    // See P2286: C++-23 will have formatting ranges to print ranges a lot
    // easier like libfmt version: fmt::print("{}", fmt::join(vec. ", ")).
    // As of now you can also use something like
    // std::ranges::copy(vec, std::ostream_iterator<int>(std::cout, " "))
    // if you don't care about the last space.

    using std::cbegin;
    using std::cend;
    std::copy(cbegin(vec),
              cend(vec),
              std::experimental::make_ostream_joiner(std::cout, ' '));
    std::cout << '\n';
}

auto main() -> int {
    auto num1{10};
    auto num2{20};
    std::cout << num1 << ' ' << num2 << '\n';

    std::swap(num1, num2);

    std::cout << num1 << ' ' << num2 << '\n';

    // Many Containers like std::vector have their own specification, even
    // classes like std::unique_ptr have their own specification
    auto vec1 = std::vector{1, 2, 3};
    auto vec2 = std::vector{4, 5, 6};

    printIntVector(vec1);
    printIntVector(vec2);

    std::swap(vec1, vec2);

    printIntVector(vec1);
    printIntVector(vec2);
}
