#include <iostream>
#include <string>


std::string sci_to_normal(std::string num_sci) {
    std::string ans;
    if (num_sci[0] == '-') ans.push_back('-');
    auto E_pos = num_sci.find_last_of('E');
    char expo_sign = num_sci[E_pos + 1];
    unsigned int expo = std::stoi(num_sci.substr(E_pos + 2));
    std::string figures = num_sci[1] + num_sci.substr(3, E_pos - 3);
    switch (expo_sign) {
        case '-':
            if (expo > 0) {
                ans += "0." + std::string(expo - 1, '0') + figures;
            } else {
                ans = num_sci.substr(0, E_pos);
            }
            break;
        case '+':
            ++expo;
            if (expo < figures.size()) {
                ans += figures.substr(0, expo) + '.' + figures.substr(expo);
            } else {
                ans += figures + std::string(expo - figures.size(), '0');
            }
            break;
    }
    return ans;
}


int main() {

    std::string num_sci;
    std::cin >> num_sci;

    std::cout << sci_to_normal(num_sci) << '\n';

    return 0;
}
