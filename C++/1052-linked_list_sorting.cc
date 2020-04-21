#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>


struct Node {
    std::string addr;
    int key;
    std::string nxt_addr;
};


int main() {

    std::ios::sync_with_stdio(false);

    int N;
    std::string head_addr;
    std::cin >> N >> head_addr;

    std::unordered_map<std::string, std::pair<int, std::string>> nexts;
    while (N--) {
        std::string addr, nxt_addr;
        int key;
        std::cin >> addr >> key >> nxt_addr;
        nexts[addr] = std::make_pair(key, nxt_addr);
    }

    std::vector<Node> nodes;
    std::string curr_addr = head_addr;
    while (curr_addr != "-1") {
        auto key_nxtaddr = nexts[curr_addr];
        nodes.push_back({curr_addr, key_nxtaddr.first, key_nxtaddr.second});
        curr_addr = key_nxtaddr.second;
    }

    if (!nodes.empty()) {
        std::sort(nodes.begin(), nodes.end(),
                  [](Node &n1, Node &n2) {return n1.key < n2.key;});
        // update nxt_addr 
        for (std::size_t i=0; i!=nodes.size() - 1; ++i) {
            nodes[i].nxt_addr = nodes[i+1].addr;
        }
        nodes.back().nxt_addr = "-1";
        std::cout << nodes.size() << ' ' << nodes.front().addr << '\n';
        for (auto &node : nodes) {
            std::cout << node.addr << ' '
                      << node.key << ' '
                      << node.nxt_addr << '\n';
        }
    } else {
        std::cout << "0 -1\n";
    }

    return 0;
}
