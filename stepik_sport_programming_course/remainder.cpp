#include <iostream>

int main() {
    long long a;
    unsigned long b;
    int c;

    std::cin >> a >> b;

    c = (a % (long long)b + (long long)b) % (long long)b;

    std::cout << c << std::endl;
}