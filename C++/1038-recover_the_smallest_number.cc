#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>


bool comp(const std::string &n1, const std::string &n2) {
    return n1 + n2 < n2 + n1;
}


std::string
recover_the_smallest_num(std::vector<std::string> &nums)
{
    std::sort(nums.begin(), nums.end(), comp);
    std::string smallest = std::accumulate(
        nums.begin(), nums.end(), std::string());
    auto bgn_iter = std::find_if(smallest.begin(), smallest.end(),
                                 [](const char &c) {return c!='0';});
    if (bgn_iter != smallest.end()) {
        smallest.erase(smallest.begin(), bgn_iter);
    } else {
        smallest = "0";
    }
    return smallest;
}


int main() {

    int N;
    std::cin >> N;

    std::vector<std::string> nums;
    while (N--) {
        std::string num;
        std::cin >> num;
        nums.push_back(num);
    }

    std::cout << recover_the_smallest_num(nums) << '\n';

    return 0;
}
