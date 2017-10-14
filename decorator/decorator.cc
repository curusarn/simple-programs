#include <iostream>
#include <string>

template<typename Call_t>
class Decorator_t {
    Call_t &call;
    const std::string name;
public:
    Decorator_t(Call_t &c, const std::string &str) : call(c), name(str) {};
    std::string operator()(int a) {
        std::cout << name << std::endl;
        return call(a) ? "yes" : "no";
    }
};

template<typename Call_t>
Decorator_t<Call_t> decorator(Call_t &c, const std::string &str) {
    return Decorator_t<Call_t>(c, str);
}

bool isOdd(int a) {
    return a % 2;
}

bool isFour(int a) {
    return a == 4;
}

bool isZero(int a) {
    return a == 0;
}

int main() {
    auto decorated_isOdd = decorator(isOdd, "isOdd");
    auto decorated_isFour = decorator(isFour, "isFour");
    auto decorated_isZero = decorator(isZero, "isZero");

    int x = 4;

    std::cout << decorated_isOdd(x) << std::endl;
    std::cout << decorated_isFour(x) << std::endl;
    std::cout << decorated_isZero(x) << std::endl;
}

