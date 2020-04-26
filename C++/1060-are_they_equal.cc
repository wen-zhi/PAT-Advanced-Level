#include <iostream>
#include <string>
#include <algorithm>


void lstrip(std::string &s, char c) {
    auto strip_end = std::find_if(s.begin(), s.end(),
                                  [c](const char x) {return x!='0';});
    s.erase(s.begin(), strip_end);
}


std::string to_standard_form(std::string num, int precision) {
    lstrip(num, '0');
    int k;
    if (!num.empty() && num[0] == '.') {
        num.erase(0, 1);
        int size_before = num.size();
        lstrip(num, '0');
        k = int(num.size()) - size_before;
        if (num.empty()) k = 0;
    } else {
        auto dot_pos = num.find('.');
        if (dot_pos == std::string::npos) {
            k = num.size();
        } else {
            k = dot_pos;
            num.erase(dot_pos, 1);
        }
    }
    int num_size = num.size();
    if (precision > num_size) {
        num += std::string(precision - num_size, '0');
    } else {
        num = num.substr(0, precision);
    }
    return std::string("0.") + num + std::string("*10^") + std::to_string(k);
}


int main() {

    int precision;
    std::string n1, n2;
    std::cin >> precision >> n1 >> n2;

    std::string n1_std = to_standard_form(n1, precision);
    std::string n2_std = to_standard_form(n2, precision);
    if (n1_std == n2_std) {
        std::cout << "YES " << n1_std;
    } else {
        std::cout << "NO " << n1_std << ' ' << n2_std;
    }
    std::cout << '\n';

    return 0;
}
