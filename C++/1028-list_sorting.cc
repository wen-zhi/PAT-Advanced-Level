#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


struct Student {
    Student() = default;
    Student(const std::string id,
            const std::string name,
            const std::string grade):
        id(id), name(name), grade(grade) {}
    std::string id;
    std::string name;
    std::string grade;
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
    std::string id, name, grade;
    for (int i=0; i<n_student; ++i) {
        std::cin >> id >> name >> grade;
        students.push_back(Student(id, name, grade));
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
