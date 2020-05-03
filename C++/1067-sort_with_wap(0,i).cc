#include <iostream>
#include <map>


int main() {

    int n_num;
    std::cin >> n_num;
    std::map<int, int> num_to_idx;
    for (int i=0; i<n_num; ++i) {
        int num;
        std::cin >> num;
        if (i != num or i == 0) {
            num_to_idx[num] = i;
        }
    }
    int count = 0;
    while (!num_to_idx.empty()) {
        int idx = num_to_idx[0];
        if (idx != 0) {
            num_to_idx[0] = num_to_idx[idx];
            num_to_idx.erase(idx);
            ++count;
        } else if (idx == 0 && num_to_idx.size() == 1) {
            num_to_idx.erase(idx);
        } else {
            for (auto &kv : num_to_idx) {
                if (kv.first != 0) {
                    num_to_idx[0] = num_to_idx[kv.first];
                    num_to_idx[kv.first] = 0;
                    ++count;
                    break;
                }
            }
        }
    }
    std::cout << count << '\n';

    return 0;
}
