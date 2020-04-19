#include <iostream>


int number_of_one(int num) {
    int ones = 0, base = 1;
    while (base <= num) {
        int right = num % base;
        int left = num / (base * 10);
        int digit = num / base % 10;
        if (digit == 0) {
            ones += left * base;
        } else if (digit == 1) {
            ones += left * base + right + 1;
        } else {
            ones += (left + 1) * base;
        }
        base *= 10;
    }
    return ones;
}


int main() {

    int num;
    std::cin >> num;

    std::cout << number_of_one(num) << '\n';

    return 0;
}
