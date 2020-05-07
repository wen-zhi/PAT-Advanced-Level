#include <iostream>
#include <string>
#include <algorithm>


// Pad a numeric string with zeros on the left in-place,
// to fill a field of the given width.
void zfill(std::string &s, std::size_t width) {
    while (s.size() != width) {
        s = '0' + s;
    }
}


int main() {

    std::string num;
    std::cin >> num;
    zfill(num, 4);
    std::string num_r(num.crbegin(), num.crend());
    if (num == num_r) {
        std::cout << num << " - " << num << " = 0000\n";
    } else {
        while (true) {
            std::sort(num.rbegin(), num.rend());
            std::string num_r(num.crbegin(), num.crend());
            auto res = std::to_string(std::stoi(num) - std::stoi(num_r));
            zfill(res, 4);
            std::cout << num << " - " << num_r << " = " << res << '\n';
            if (res == "6174") break;
            else num = res;
        }
    }

    return 0;
}
