#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int high_line = 80;  // default to 80


struct People {
    // constructors
    People() = default;
    People(std::string id_num, int virtue, int talent):
        id_num(id_num), virtue(virtue), talent(talent), total_value(virtue + talent)
    {
        if (virtue >= high_line) {
            if (talent >= high_line)
                type = 1;  // sage
            else
                type = 2;  // nobleman
        } else {
            if (virtue >= talent)
                type = 3;  // fool man
            else
                type = 4;  // small man
        }   
    }
    // members
    std::string id_num;
    int virtue, talent, total_value, type;
};


bool operator<(const People &p1, const People &p2) {
    if (p1.type < p2.type)
        return true;
    else if (p1.type > p2.type)
        return false;
    // rank by total_value
    if (p1.total_value > p2.total_value)
        return true;
    else if (p1.total_value < p2.total_value)
        return false;
    // rank by virtue
    if (p1.virtue > p2.virtue)
        return true;
    else if (p1.virtue < p2.virtue)
        return false;
    // rank by id_num
    return p1.id_num < p2.id_num;
}


std::ostream &operator<<(std::ostream &os, const People &p) {
    os << p.id_num << ' ' << p.virtue << ' ' << p.talent;
    return os;
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_people, low_line;
    std::cin >> n_people >> low_line;
    // set high_line
    std::cin >> high_line;

    std::vector<People> all_people;
    while (n_people--) {
        std::string id_num;
        int virtue, talent;
        std::cin >> id_num >> virtue >> talent;
        if (virtue < low_line || talent < low_line) continue;
        all_people.push_back(People(id_num, virtue, talent));
    }

    std::sort(all_people.begin(), all_people.end());
    std::cout << all_people.size() << '\n';
    for (auto &people : all_people) {
        std::cout << people << '\n';
    }

    return 0;
}
