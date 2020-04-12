#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


struct Student {
    std::string id;
    std::string name;
    int grade;
};


bool comp(const Student &stu1, const Student &stu2, const int col) {
    if (col == 2) {
        if (stu1.name < stu2.name) {
            return 1;
        } else if (stu1.name > stu2.name) {
            return 0;
        }
    }
    if (col == 3) {
        if (stu1.grade < stu2.grade) {
            return 1;
        } else if (stu1.grade > stu2.grade) {
            return 0;
        }
    }
    return stu1.id < stu2.id;
}


int main() {

    int n_student, col;
    std::cin >> n_student >> col;

    std::vector<Student> students;
    std::string id, name;
    int grade;
    for (int i=0; i<n_student; ++i) {
        std::cin >> id >> name >> grade;
        students.push_back({id, name, grade});
    }

    using std::placeholders::_1;
    using std::placeholders::_2;
    std::sort(students.begin(), students.end(),
              std::bind(comp, _1, _2, col));
    for (auto student : students) {
        std::cout << student.id << ' '
                  << student.name << ' '
                  << student.grade << '\n';
    }

    return 0;
}
