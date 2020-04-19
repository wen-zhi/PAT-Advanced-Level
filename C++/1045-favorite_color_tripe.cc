#include <iostream>
#include <vector>


int longest_stripe(std::vector<int> &given_stripe, std::vector<int> &color_order) {
    std::vector<int> L(given_stripe.size());
    for (std::size_t j=0; j<given_stripe.size(); ++j) {
        int max_len = 1;
        for (std::size_t i=0; i<j; ++i) {
            if (color_order[given_stripe[i]] <= color_order[given_stripe[j]]) {
                max_len = L[i] + 1 > max_len ? L[i] + 1 : max_len;
            }
        }
        L[j] = max_len;
    }
    return L.back();
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_color;
    std::cin >> n_color;
    std::vector<int> color_order(n_color + 1);
    std::vector<bool> color_exist(n_color + 1);

    int n_favorite_color;
    std::cin >> n_favorite_color;
    for (int i=0; i<n_favorite_color; ++i) {
        int color;
        std::cin >> color;
        color_exist[color] = true;
        color_order[color] = i;
    }

    int stripe_len;
    std::cin >> stripe_len;
    std::vector<int> given_stripe;
    while (stripe_len--) {
        int color;
        std::cin >> color;
        if (color_exist[color])
            given_stripe.push_back(color);
    }

    std::cout << longest_stripe(given_stripe, color_order) << '\n';

    return 0;
}
