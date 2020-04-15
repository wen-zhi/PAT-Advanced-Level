#include <iostream>
#include <string>
#include <unordered_map>


std::string
common_prefix(std::string &word_a, std::string &word_b,
              std::unordered_map<std::string, std::string> &nexts)
{
    std::unordered_map<std::string, bool> visited;
    while (word_a != "-1") {
        visited[word_a] = true;
        word_a = nexts[word_a];
    }
    while (word_b != "-1") {
        if (visited[word_b]) {
            return word_b;
        }
        word_b = nexts[word_b];
    }
    return "-1";
}


int main() {

    // turn off sync with C stream
    std::ios::sync_with_stdio(false);

    std::string word_a, word_b;
    int n_node;
    std::cin >> word_a >> word_b >> n_node;

    std::unordered_map<std::string, std::string> nexts;
    std::string addr, _, next;
    for (int i=0; i<n_node; ++i) {
        std::cin >> addr >> _ >> next;
        nexts[addr] = next;
    }

    std::cout << common_prefix(word_a, word_b, nexts) << '\n';
    
    return 0;
}
