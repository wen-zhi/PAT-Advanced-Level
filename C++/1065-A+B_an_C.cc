#include <iostream>


int main() {

    int n_test_case;
    std::cin >> n_test_case;
    for (int i=1; i<=n_test_case; ++i) {
        long long int a, b, c;
        std::cin >> a >> b >> c;
        bool res;
        if (a > 0 && b > 0) {
            if (c < 0) {
                res = true;
            } else {
                res = a > c - b;
            }
        } else if (a < 0 && b < 0) {
            if (c >= 0) {
                res = false;
            } else {
                res = a > c - b;
            }
        } else {
            res = a + b > c;
        }
        std::cout << "Case #" << i << ": ";
        std::cout << (res == true ? "true" : "false") << '\n';
    }

    return 0;
}
