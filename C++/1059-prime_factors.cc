#include <iostream>
#include <map>
#include <set>


std::set<long int> primes;


void factorize(long int num, std::map<long int, int> &res) {
    auto iter = primes.find(num);
    if (iter != primes.end()) {
        res[num] += 1;
        return;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            factorize(i, res);
            factorize(num / i, res);
            return;
        }
    }
    primes.insert(num);
    res[num] += 1;
}


int main() {

    long int num;
    std::cin >> num;

    std::map<long int, int> res;
    factorize(num, res);

    std::cout << num << '=';
    auto iter = res.begin();
    std::cout << iter->first;
    if (iter->second > 1) {
        std::cout << '^' << iter->second;
    }
    for (++iter; iter!=res.end(); ++iter) {
        std::cout << '*' << iter->first;
        if (iter->second > 1) {
            std::cout << '^' << iter->second;
        }
    }
    std::cout << '\n';

    return 0;
}
