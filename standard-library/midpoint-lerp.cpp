import <cmath>;
import <initializer_list>;
import <iostream>;
import <numeric>;

auto main() -> int {
    std::cout << std::midpoint(10, 100) << '\n';

    for (auto num : {0.0, 0.2, 0.4, 0.6, 0.8, 1.0}) {
        std::cout << std::lerp(10, 100, num) << '\n'; // a + t (b - a)
    }
}
