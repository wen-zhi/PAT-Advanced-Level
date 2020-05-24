#include <iostream>
#include <string>
#include <array>


std::array<std::string, 10> digit_to_hanzi = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
std::array<std::string, 9> pos_to_thounsands = {
    "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};


std::string reading_number(int n) {
    if (n == 0) return "ling";
    std::string res;
    if (n < 0) {
        res += "Fu";
        n *= -1;
    }
    std::string n_str = std::to_string(n);
    int zeros = 0;
    for (std::size_t i = 0; i < n_str.length(); ++i) {
        std::size_t pos = n_str.length() - i - 1;  // counting from right
        int digit = n_str[i] - '0';
        if (digit != 0) {
            if (zeros > 0) res += " ling";
            if (res.size() > 0) {
                res += " " + digit_to_hanzi[digit];
            } else {
                res += digit_to_hanzi[digit];
            }
            // no need to output '个'位
            if (pos > 0) res += " " + pos_to_thounsands[pos];
            zeros = 0;
        } else {
            zeros += 1;
            // handling numbers like '100001'
            if (pos == 4 && zeros < 4) res += " Wan";
        }
    }
    return res;
}


int main() {

    int n;
    std::cin >> n;
    std::cout << reading_number(n) << '\n';

    return 0;
}
