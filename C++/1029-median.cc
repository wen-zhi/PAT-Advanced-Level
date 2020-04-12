#include <iostream>
#include <vector>


long int
median(std::vector<long int> &seq1,
       std::vector<long int> &seq2) {
    auto mid_pos = (seq1.size() + seq2.size() + 1) / 2;
    decltype(mid_pos) pos = 0;
    auto iter1 = seq1.begin(), iter2 = seq2.begin();
    long int num = -1;
    while (iter1 != seq1.end() && iter2 != seq2.end()) {
        if (*iter1 < *iter2) {
            num = *iter1++;
        } else {
            num = *iter2++;
        }
        if (++pos == mid_pos) {
            return num;
        }
    }
    if (iter1 != seq1.end()) {
        num = *(iter1 + mid_pos - pos - 1);
    } else {
        num = *(iter2 + mid_pos - pos - 1);
    }
    return num;
}


int main() {

    // turn off sync with standard C streams
    std::ios::sync_with_stdio(false);

    int n1, n2;
    std::vector<long int> seq1, seq2;
    long int num;
    std::cin >> n1;
    for (int i=0; i<n1; ++i) {
        std::cin >> num;
        seq1.push_back(num);
    }
    std::cin >> n2;
    for (int i=0; i<n2; ++i) {
        std::cin >> num;
        seq2.push_back(num);
    }
    std::cout << median(seq1, seq2) << '\n';

    return 0;
}
