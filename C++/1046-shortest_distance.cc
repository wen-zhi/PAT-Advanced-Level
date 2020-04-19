#include <iostream>
#include <vector>


int main() {

    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    std::vector<int> cum_sum = {0};
    while (N--) {
        int num;
        std::cin >> num;
        cum_sum.push_back(cum_sum.back() + num);
    }

    int M;
    std::cin >> M;
    while (M--) {
        int i, j;
        std::cin >> i >> j;
        --i, --j;
        if (j < i) {
            std::swap(i, j);
        }
        int dist = cum_sum[j] - cum_sum[i];
        int alt_dist = cum_sum[i] + cum_sum.back() - cum_sum[j];
        std::cout << (dist < alt_dist ? dist : alt_dist) << '\n';
    }

    return 0;
}
