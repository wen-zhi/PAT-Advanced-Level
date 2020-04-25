#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>


bool comp(std::pair<const int, int> &kv1, std::pair<const int, int> &kv2) {
    return kv1.second < kv2.second;
}


int main() {

    std::ios::sync_with_stdio(false);

    int col, row;
    std::cin >> col >> row;
    
    std::unordered_map<int, int> counter;
    for (int i=0; i<row; ++i) {
        for (int j=0; j<col; ++j) {
            int color;
            std::cin >> color;
            counter[color] += 1;
        }
    }

    auto dominant = std::max_element(counter.begin(), counter.end(), comp);
    std::cout << dominant->first << '\n';

    return 0;
}
