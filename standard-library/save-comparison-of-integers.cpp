import <utility>;

auto main() -> int {
    // Problem: -1 > 1u evaluates true because -1 as a signed integer is
    // promoted to an unsigned type
    // Solution:
    static_assert(std::cmp_less(-1, 1U));
    static_assert(std::cmp_greater_equal(1U, -1));
    static_assert(std::cmp_not_equal(1U, -1));

    // std::cmp_equal(-1.0, 1U) won't compile since -1.0 is not a signed or
    // unsigned integer type
}
