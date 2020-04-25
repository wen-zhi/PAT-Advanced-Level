#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Billionaire {
    std::string name;
    int age;
    int net_worth;    
};


bool comp(const Billionaire &s1, const Billionaire &s2) {
    if (s1.net_worth > s2.net_worth) {
        return true;
    } else if (s1.net_worth < s2.net_worth) {
        return false;
    }
    if (s1.age < s2.age) {
        return true;
    } else if (s1.age > s2.age) {
        return false;
    }
    return s1.name < s2.name;
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_billionaire, n_query;
    std::cin >> n_billionaire >> n_query;

    std::vector<Billionaire> database;
    while (n_billionaire--) {
        std::string name;
        int age, net_worth;
        std::cin >> name >> age >> net_worth;
        database.push_back({name, age, net_worth});
    }

    std::sort(database.begin(), database.end(), comp);
    
    for (int i=1; i<=n_query; ++i) {
        int max_output, a_min, a_max;
        std::cin >> max_output >> a_min >> a_max;
        std::cout << "Case #" << i << ":\n";
        int count = 0;
        for (Billionaire &billionaire : database) {
            if (billionaire.age >= a_min && billionaire.age <= a_max) {
                std::cout << billionaire.name << ' '
                          << billionaire.age << ' '
                          << billionaire.net_worth << '\n';
                ++count;
            }
            if (count >= max_output) break;
        }
        if (count == 0) {
            std::cout << "None\n";
        }
    }

    return 0;
}
