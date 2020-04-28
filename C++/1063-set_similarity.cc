#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>


int main() {

    std::ios::sync_with_stdio(false);

    int n_set;
    std::cin >> n_set;
    std::vector<std::unordered_set<int>> sets;
    while (n_set--) {
        int n_num;
        std::cin >> n_num;
        std::unordered_set<int> set;
        int num;
        while (n_num--) {
            std::cin >> num;
            set.insert(num);
        }
        sets.push_back(set);
    }

    int n_query;
    std::cin >> n_query;
    while (n_query--) {
        int a, b;
        std::cin >> a >> b;
        --a, --b;
        double n_c = 0.;
        if (sets[a].size() < sets[b].size()) {
            for (auto &num : sets[a]) {
                if (sets[b].find(num) != sets[b].end()) ++n_c;
            }
        } else {
            for (auto &num : sets[b]) {
                if (sets[a].find(num) != sets[a].end()) ++n_c;
            }
        }
        double n_t = sets[a].size() + sets[b].size() - n_c;
        std::cout << std::fixed << std::setprecision(1)
                  << n_c / n_t * 100 << '%' << '\n'
                  << std::defaultfloat;
    }

    return 0;
}
