#include <iostream>
#include <vector>
#include <limits>


struct Solution {
    std::size_t bgn, end;
};


std::vector<Solution>
shopping_in_mars(std::vector<int> &diamonds, int amount)
{
    std::vector<Solution> solutions;
    std::vector<Solution> nearest_solutions;
    int nearest_amount = std::numeric_limits<int>::max();

    std::size_t bgn = 0, end = 0;
    int part_sum = 0;
    while (end < diamonds.size()) {
        while (end < diamonds.size() and part_sum < amount) {
            part_sum += diamonds[end++];
        }
        while (part_sum >= amount) {
            if (part_sum == amount) {
                solutions.push_back({bgn, end - 1});
            } else {
                if (part_sum < nearest_amount) {
                    nearest_amount = part_sum;
                    nearest_solutions.clear();
                    nearest_solutions.push_back({bgn, end - 1});
                } else if (part_sum == nearest_amount) {
                    nearest_solutions.push_back({bgn, end - 1});
                }
            }
            part_sum -= diamonds[bgn++];
        }
    }
    if (!solutions.empty()) {
        return solutions;
    } else {
        return nearest_solutions;
    }
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_diamond, amount;
    std::cin >> n_diamond >> amount;

    std::vector<int> diamonds;
    while (n_diamond--) {
        int diamond;
        std::cin >> diamond;
        diamonds.push_back(diamond);
    }

    std::vector<Solution> solutions = shopping_in_mars(diamonds, amount);
    for (auto &solution : solutions) {
        std::cout << solution.bgn + 1 << '-'
                  << solution.end + 1 << '\n';
    }

    return 0;
}
