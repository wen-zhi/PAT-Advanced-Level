#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


struct Node {
    int value = 0;
    bool is_used = false;
};


std::vector<int>
find_coins(std::vector<int> coins, const int total_amount)
{
    std::sort(coins.rbegin(), coins.rend());
    // shape: (total_amount + 1, coins.size() + 1)
    std::vector<std::vector<Node>> M(total_amount + 1,
                                     std::vector<Node>(coins.size() + 1));
    for (int v = 1; v <= total_amount; ++v) {
        for (std::size_t j=1; j<=coins.size(); ++j) {
            int coin = coins[j-1];
            if (coin <= v) {
                int alt_v = M[v-coin][j-1].value + coin;
                if (alt_v >= M[v][j-1].value) {
                    M[v][j].value = alt_v;
                    M[v][j].is_used = true;
                } else {
                    M[v][j].value = M[v][j-1].value;
                    M[v][j].is_used = false;
                }
            } else {
                M[v][j].value = M[v][j-1].value;
                M[v][j].is_used = false;
            }
        }
    }
    std::vector<int> path;
    if (M[total_amount][coins.size()].value == total_amount) {
        int v = total_amount;
        for (std::size_t j=coins.size(); j>0; --j) {
            if (M[v][j].is_used) {
                path.push_back(coins[j-1]);
                v -= coins[j-1];
            }
        }
    }
    return path;
}


int main() {
    int n_coin, total_amount;
    std::cin >> n_coin >> total_amount;
    std::vector<int> coins;
    while (n_coin--) {
        int coin;
        std::cin >> coin;
        coins.push_back(coin);
    }

    std::vector<int> solution = find_coins(coins, total_amount);
    if (!solution.empty()) {
        auto iter = solution.begin();
        std::cout << *iter;
        for (++iter; iter!=solution.end(); ++iter) {
            std::cout << ' ' << *iter;
        }
    } else {
        std::cout << "No Solution";
    }
    std::cout << '\n';

    return 0;
}
