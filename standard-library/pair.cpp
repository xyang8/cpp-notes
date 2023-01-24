import <iostream>;
import <string>;
import <utility>;

auto returnPair() {
    using namespace std::string_literals;
    return std::make_pair("Italia"s, "Roma"s);
}

auto main() -> int {
    using namespace std::string_literals;
    auto p1 = std::pair{"pi"s, 3.14};
    auto p2 = std::make_pair("e"s, 2.71);

    // Supports operator== and operator<=>
    // Compares first .first and then .second
    if (p1 != p2) {
        std::cout << "p1 != p2\n";
    }

    // Access to data
    [[maybe_unused]] auto pi_value = std::get<1>(p1);

    auto& [name, value] = p2; // Structured binding
    p2 = std::make_pair("e"s, 2.718);
    std::cout << name << '=' << value << '\n';
    value = 2.7182;
    std::cout << p2.first << '=' << p2.second << '\n';

    auto [country, capital] = returnPair();
    std::cout << country << ": " << capital << '\n';

    // swap is specified
    std::swap(p1, p2);
}
