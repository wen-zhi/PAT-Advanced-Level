#include <iostream>
#include <string>
#include <array>
#include <stack>


using BITree = std::array<int, 100001>;


int get_sum(const BITree &bitree, std::size_t pos) {
    int sum = 0;
    while (pos > 0) {
        sum += bitree[pos];
        pos -= (pos & (-pos));
    }
    return sum;
}


void update(BITree &bitree, std::size_t pos, int value) {
    while (pos < bitree.size()) {
        bitree[pos] += value;
        pos += (pos & (-pos));
    }
}


int find_freq(const BITree &bitree, int target_freq) {
    int low = 1, high = 100000;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (get_sum(bitree, mid) < target_freq) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}


int main() {

    std::ios::sync_with_stdio(false);

    BITree bitree;

    int n_op;
    std::cin >> n_op;
    std::stack<int> stack;
    while (n_op--) {
        std::string op;
        std::cin >> op;
        if (op == "Push") {
            int value;
            std::cin >> value;
            stack.push(value);
            update(bitree, value, 1);
        } else if (!stack.empty()) {
            if (op == "Pop") {
                int value = stack.top();
                stack.pop();
                update(bitree, value, -1);
                std::cout << value << '\n';
            } else {
                int target_freq = (stack.size() + 1) / 2;
                std::cout << find_freq(bitree, target_freq) << '\n';
            }
        } else {
            std::cout << "Invalid\n";
        }
    }

    return 0;
}
