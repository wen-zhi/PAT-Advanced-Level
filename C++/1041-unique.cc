#include <iostream>
#include <vector>
#include <array>


int main() {

    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> nums;
    std::array<int, 10001> counter;
    while (N--) {
        int num;
        std::cin >> num;
        nums.push_back(num);
        counter[num] += 1;
    }

    bool no_winner = true;
    for (int num : nums) {
        if (counter[num] == 1) {
            std::cout << num << '\n';
            no_winner = false;
            break;
        }
    }
    if (no_winner) {
        std::cout << "None\n";
    }

    return 0;
}
