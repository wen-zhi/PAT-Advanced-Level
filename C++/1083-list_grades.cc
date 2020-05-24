#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


struct Student {
    std::string name, ID;
    int grade;    
};


int lower_bound(const std::vector<Student> &students, int grade) {
    int low = 0, high = students.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (students[mid].grade > grade) {
            low = mid + 1;
        } else if (students[mid].grade < grade) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return low;
}


int upper_bound(const std::vector<Student> &students, int grade) {
    int low = 0, high = students.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (students[mid].grade >= grade) {
            low = mid + 1;
        } else if (students[mid].grade < grade) {
            high = mid - 1;
        }
    }
    return low;
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_student;
    std::cin >> n_student;
    std::vector<Student> students;
    while (n_student--) {
        std::string name, ID;
        int grade;    
        std::cin >> name >> ID >> grade;
        students.push_back({name, ID, grade});
    }
    int bgn_grade, end_grade;
    std::cin >> bgn_grade >> end_grade;
    std::sort(students.begin(), students.end(),
              [](const Student &s1, const Student &s2)
                {return s1.grade > s2.grade;});
    int lower = lower_bound(students, end_grade);
    int upper = upper_bound(students, bgn_grade);
    if (lower != upper) {
        while (lower != upper) {
            std::cout << students[lower].name << ' '
                    << students[lower].ID << '\n';
            ++lower;
        }
    } else {
        std::cout << "NONE\n";
    }

    return 0;
}
