import <string>;
import <tuple>;
import <iostream>;

// std::tie can be used to define operator<=>
class Foo {
  public:
    Foo(int i, std::string s, bool b) :
        m_int{i},
        m_str{std::move(s)},
        m_bool{b} {
    }

    auto operator<=>(const Foo& rhs) const {
        return std::tie(m_int, m_str, m_bool)
           <=> std::tie(rhs.m_int, rhs.m_str, rhs.m_bool);
    }

  private:
    int m_int;
    std::string m_str;
    bool m_bool;
};

auto main() -> int {
    using namespace std::string_literals;
    auto t = std::make_tuple("eins"s, 1, 1.0, 1.0F);

    [[maybe_unused]] auto t_double = std::get<double>(t);

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

    std::cout << "Tuple size = "
              << std::tuple_size<std::tuple<int, double, float>>::value
              << '\n';
    std::cout << "Tuple size = " << std::tuple_size<decltype(t)>::value
              << '\n';

    auto str{"a string"s};
    [[maybe_unused]] auto tuple_with_ref = std::make_tuple(1, std::ref(str));
    std::cout << std::get<1>(tuple_with_ref) << '\n';
    str = "another string"s;
    std::cout << std::get<1>(tuple_with_ref) << '\n';

    [[maybe_unused]] auto sum = std::tuple_cat(t, tuple_with_ref);

    auto f1 = Foo{1, "Hello"s, false};
    auto f2 = Foo{1, "World"s, false};
    std::cout << std::boolalpha << (f1 < f2) << '\n';

    // Usefull for generic code using templates and template
    // metaprogramming, t2 only needs to suport std::get<T>!!
    auto t2 = std::make_tuple(1, "string", true);
    auto f3 = std::make_from_tuple<Foo>(t2);

    auto lambda = [](auto a, auto b) -> decltype(a + b) { return a + b; };
    std::cout << std::apply(lambda, std::tuple{1, 2}) << '\n';
}
