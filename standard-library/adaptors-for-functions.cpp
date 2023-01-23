import <functional>;
import <iostream>;
import <map>;
import <utility>;

constexpr auto divide(double p, double q) -> double {
    return p / q;
};

auto main() -> int {
    using namespace std::placeholders;

    // Today we mostyle use lambdas instead of std::bind, std::bind_front and
    // automatic type deduction instead of std::function
    std::function<double(double, double)> myDiv1 = std::bind(divide, _1, _2);
    std::function<double(double)> myDiv2 = std::bind(divide, 4.0, _1);
    std::function<double(double)> myDiv3 = std::bind(divide, _1, 2);
    std::function<double(double)> myDiv4 = std::bind_front(divide, 4.0);

    std::cout << divide(4.0, 2) << '\n';
    std::cout << myDiv1(4.0, 2) << '\n';
    std::cout << myDiv2(2) << '\n';
    std::cout << myDiv3(4.0) << '\n';
    std::cout << myDiv4(2) << '\n';

    // Example where you have to specify the type of callable explicitly, and
    // can't be replaced by auto
    std::map<const char, std::function<int(int, int)>> tab;
    tab.insert(std::make_pair('+', [](int m, int n) { return m + n; }));
    tab.insert(std::make_pair('-', [](int m, int n) { return m + n; }));

    std::cout << tab['+'](3, 4) << '\n';
    std::cout << tab['-'](9, 3) << '\n';
}
