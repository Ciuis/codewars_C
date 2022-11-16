#include <iostream>

int main() {
    int a, b, c;

    std::cin >> a >> b;

    c = a % b == 0 ? (a / b) : (int(double(a) / double(b)) + 1);
    //c = int(double(a) / double(b)) + 1;

    std::cout << c << std::endl;
}