#include <iostream>
#include <array>
#include <iomanip>


int main() {

    std::ios::sync_with_stdio(false);

    int word_a, word_b, n_node;
    std::cin >> word_a >> word_b >> n_node;

    std::array<int, 100000> nexts;
    int addr, next;
    char _;
    for (int i=0; i<n_node; ++i) {
        std::cin >> addr >> _ >> next;
        nexts[addr] = next;
    }
    
    std::array<int, 100000> visited;
    while (word_a != -1) {
        visited[word_a] = 1;
        word_a = nexts[word_a];
    }
    while (word_b != -1) {
        if (visited[word_b]) break;
        word_b = nexts[word_b];
    }
    if (visited[word_b]) {
        std::cout << std::setfill('0')
                  << std::setw(5)
                  << word_b << '\n';
    } else {
        std::cout << -1 << '\n';
    }

    return 0;
}
