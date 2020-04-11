#include <iostream>
#include <vector>


std::string to_nary(int n) {
    if (n == 0) return "00";

    std::string res;
    int digit;
    while (n != 0) {
        digit = n % 13;
        n = n / 13;
        if (digit < 10) {
            res = std::to_string(digit) + res;
        } else {
            res = std::string(1, char('A' + digit - 10)) + res;
        }
    }
    if (res.size() < 2) {
        res = std::string("0") + res;
    }
    return res;
}


std::string color_in_mars(int r, int g, int b) {
    std::string c_in_mars = "#";
    std::vector<int> colors = {r, g, b};
    for (int color : colors) {
        c_in_mars += to_nary(color);
    }
    return c_in_mars;
}


int main() {

    int r, g, b;
    std::cin >> r >> g >> b;
    std::cout << color_in_mars(r, g, b) << '\n';

    return 0;
}
