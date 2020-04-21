#include <iostream>
#include <string>
#include <unordered_set>


int main() {

    std::ios::sync_with_stdio(false);

    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);   
    std::unordered_set<char> s2_set(s2.begin(), s2.end());

    for (char c : s1) {
        if (s2_set.find(c) != s2_set.end()) {
            continue;
        }
        std::cout << c;
    }
    std::cout << '\n';

    return 0;
}
