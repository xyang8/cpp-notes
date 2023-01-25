import <functional>;
import <iostream>;
import <vector>;

class Bar {
  public:
    explicit constexpr Bar(std::reference_wrapper<int> num) : m_num{num} {};

  private:
    std::reference_wrapper<int> m_num;
};

auto foo() {
    std::cout << "foo called\n";
}

constexpr auto addTwo(auto num) {
    num += 2;
}

auto main() -> int {
    // Problem: Store references in a vector: std::vector<int&>{...}
    // (You can store pointers in a vector!)
    int num{1};
    auto vec1 =
        std::vector<std::reference_wrapper<int>>{num};  // Implicit conversion
    auto vec2 = std::vector{std::ref(num)};
    auto vec3 =
        std::vector{std::cref(num)};  // std::reference_wrapper<const T>
    num = 2;
    std::cout << vec2[0].get() << '\n';

    // Problem: Copy or assign instances of classes storing a reference:
    auto b1 = Bar{std::ref(num)};
    auto b2 = Bar{num};
    b1 = b2;

    typedef void func();
    std::reference_wrapper<func> refWrap{foo};
    refWrap();

    addTwo(num);
    std::cout << num << '\n';
    addTwo(std::ref(num));
    std::cout << num << '\n';
    // print(std::cref(num)); // ERROR!
}
