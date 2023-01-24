import <string>;
import <tuple>;
import <iostream>;

auto main() -> int {
    using namespace std::string_literals;
    auto t1 = std::make_tuple("eins"s, 1, 1.0, 1.0F);

    [[maybe_unused]] auto t1_double = std::get<double>(t1);

    // Error if multiple elements of the requested type are contained:
    // auto t2 = std::make_tuple(1, 2);
    // auto value = std::get<int>(t2);

    // Also supports operator==, operator<=>, structured binding etc.
    // Compare to its little brother std::pair in pair.cpp

    // If you want to ignore certain elements, you can use std::ignore and
    // std::tie. Structured binding does not support std::ignore.
    int one{};
    int three{};
    int four{};
    std::tie(one, std::ignore, three, four) = std::make_tuple(1, 2, 3, 4);
}
