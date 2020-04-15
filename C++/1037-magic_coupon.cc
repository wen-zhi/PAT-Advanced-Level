#include <iostream>
#include <vector>
#include <algorithm>


int main() {

    // turn off sync with C streams
    std::ios::sync_with_stdio(false);

    int n_coupon, n_product;
    
    std::cin >> n_coupon;
    std::vector<int> pos_coupons, neg_coupons;
    while (n_coupon--) {
        int coupon;
        std::cin >> coupon;
        if (coupon > 0) {
            pos_coupons.push_back(coupon);
        } else {
            neg_coupons.push_back(coupon);
        }
    }
    std::sort(pos_coupons.rbegin(), pos_coupons.rend());
    std::sort(neg_coupons.begin(), neg_coupons.end());

    std::cin >> n_product;
    std::vector<int> pos_products, neg_products;
    while (n_product--) {
        int product;
        std::cin >> product;
        if (product > 0) {
            pos_products.push_back(product);
        } else {
            neg_products.push_back(product);
        }
    }
    std::sort(pos_products.rbegin(), pos_products.rend());
    std::sort(neg_products.begin(), neg_products.end());

    int money = 0;
    for (auto c_iter=pos_coupons.begin(), p_iter=pos_products.begin();
         c_iter!=pos_coupons.end() && p_iter!=pos_products.end();
         ++c_iter, ++p_iter) {
        money += (*c_iter) * (*p_iter);
    }
    for (auto c_iter=neg_coupons.begin(), p_iter=neg_products.begin();
         c_iter!=neg_coupons.end() && p_iter!=neg_products.end();
         ++c_iter, ++p_iter) {
        money += (*c_iter) * (*p_iter);
    }
    std::cout << money << '\n';

    return 0;
}
