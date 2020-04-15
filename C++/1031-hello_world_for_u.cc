#include <iostream>
#include <string>
#include <sstream>


std::string convert_to_U(std::string s) {
    int n1 = (s.size() + 2) / 3;
    int n2 = (s.size() + 2) - 2 * n1;
    std::string U;
    for (int i=0; i<n1-1; ++i) {
        std::ostringstream line;
        line << s[i]
             << std::string(n2 - 2, ' ')
             << s[s.size()-1-i] << '\n';
        U += line.str();
    }
    U += s.substr(n1-1, n2);
    return U;
}


int main() {

    std::string s;    
    std::cin >> s;
    std::cout << convert_to_U(s) << '\n';

    return 0;
}