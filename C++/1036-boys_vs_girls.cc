#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct Student {
    std::string name, id;
    int grade;
};


bool comp(const Student &s1, const Student &s2) {
    return s1.grade < s2.grade;
}


int main() {

    int n_student;
    std::cin >> n_student;
    
    std::vector<Student> boys, girls;
    while (n_student--) {
        std::string name, id;
        char gender;
        int grade;
        std::cin >> name >> gender >> id >> grade;
        if (gender == 'M') {
            boys.push_back({name, id, grade});
        } else {
            girls.push_back({name, id, grade});
        }
    }

    Student top_girl, bottom_boy;
    if (!girls.empty()) {
        top_girl = *std::max_element(girls.begin(), girls.end(), comp);
        std::cout << top_girl.name << ' ' << top_girl.id << '\n';
    } else {
        std::cout << "Absent\n";
    }
    if (!boys.empty()) {
        bottom_boy = *std::min_element(boys.begin(), boys.end(), comp);
        std::cout << bottom_boy.name << ' ' << bottom_boy.id << '\n';
    } else {
        std::cout << "Absent\n";
    }
    if (top_girl.name != std::string() &&
        bottom_boy.name != std::string()) {
        std::cout << top_girl.grade - bottom_boy.grade << '\n';
    } else {
        std::cout << "NA\n";
    }

    return 0;
}
