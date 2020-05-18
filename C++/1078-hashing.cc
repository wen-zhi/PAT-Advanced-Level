#include <iostream>
#include <vector>
#include <cmath>


class HashTable {
public:
    HashTable() = default;
    HashTable(std::size_t given_size)
        {table_size = _next_prime(given_size); data = std::vector<int>(table_size, -1);}
    int insert(int value);
private:
    std::size_t table_size;
    std::vector<int> data;
    std::size_t _next_prime(std::size_t given_size);
};


int HashTable::insert(int value) {
    int idx = -1;
    int i = 0, max_i = table_size / 2;
    while (i <= max_i) {
        int pos = (value + i * i) % table_size;
        if (data[pos] == -1) {
            idx = pos;
            data[idx] = value;
            break;
        }
        ++i;
    }
    return idx;
}


std::size_t HashTable::_next_prime(std::size_t given_size) {
    std::size_t next = given_size;
    if (next < 3) return 2;
    if (next % 2 == 0) ++next;
    while (true) {
        int i = int(std::sqrt(next));
        while (i > 2) {
            if (next % i == 0) {
                break;
            } else {
                --i;
            }
        }
        if (i == 2) {
            break;
        } else {
            next += 2;
        }
    }
    return next;
}


int main() {

    std::size_t given_size;
    int n_num;
    std::cin >> given_size >> n_num;

    auto hash_table = HashTable(given_size);
    for (int i=0; i<n_num; ++i) {
        int num;
        std::cin >> num;
        int idx = hash_table.insert(num);
        if (i > 0) std::cout << ' ';
        if (idx != -1) {
            std::cout << idx;
        } else {
            std::cout << '-';
        }
    }
    std::cout << '\n';

    return 0;
}
