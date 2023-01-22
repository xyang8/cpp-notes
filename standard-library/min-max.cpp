import <algorithm>;
import <cmath>;
import <initializer_list>;
import <iostream>;
import <string>;
import <string_view>;

auto main() -> int {
    std::cout << std::max(1, 2) << '\n';

    auto min = std::min({-3, -1, 0, 2}, [](auto x, auto y) {
        return std::abs(x) < std::abs(y);
    });
    std::cout << min << '\n';

    constexpr auto comp_word_size = [](std::string_view s1,
                                       std::string_view s2) constexpr {
        return s1.size() < s2.size();
    };
    using namespace std::string_literals;
    auto words = {"dream"s, "awesome"s, "dog"s, "city"s};
    auto [shortest_word, longest_word] = std::minmax(words, comp_word_size);
    std::cout << shortest_word << ' ' << longest_word << '\n';
}
