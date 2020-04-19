#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main() {

    std::ios::sync_with_stdio(false);

    int n_student;
    std::size_t n_course;
    std::cin >> n_student >> n_course;

    std::vector<std::vector<std::string>> course_to_stu(n_course + 1);
    while (n_student--) {
        std::string name;
        int n_reg;
        std::cin >> name >> n_reg;
        while (n_reg--) {
            std::size_t course;
            std::cin >> course;
            course_to_stu[course].push_back(name);
        }
    }

    for (std::size_t course=1; course<=n_course; ++course) {
        std::vector<std::string> students = course_to_stu[course];
        std::cout << course << ' ' << students.size() << '\n';
        std::sort(students.begin(), students.end());
        for (std::string &student : students) {
            std::cout << student << '\n';
        }
    }

    return 0;
}
