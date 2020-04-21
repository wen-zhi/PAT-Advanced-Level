#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>


std::vector<std::pair<int, int>>
find_coins(const std::vector<int> &coins, int amount)
{
    std::vector<std::pair<int, int>> solutions;
    std::unordered_set<int> memo;
    for (auto v1 : coins) {
        auto v2_iter = memo.find(amount - v1);
        if (v2_iter != memo.end()) {
            if (v1 < *v2_iter) 
                solutions.push_back(std::make_pair(v1, *v2_iter));
            else
                solutions.push_back(std::make_pair(*v2_iter, v1));
        }
        memo.insert(v1);
    }
    return solutions;
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_coin, amount;
    std::cin >> n_coin >> amount;

    std::vector<int> coins;
    while (n_coin--) {
        int coin;
        std::cin >> coin;
        coins.push_back(coin);
    }

    auto solutions = find_coins(coins, amount);
    if (!solutions.empty()) {
        auto res_iter = std::min_element(solutions.begin(), solutions.end());
        std::cout << res_iter->first << ' ' << res_iter->second << '\n';
    } else {
        std::cout << "No Solution\n";
    }

    return 0;
}
