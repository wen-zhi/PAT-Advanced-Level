#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>


int main() {

    std::ios::sync_with_stdio(false);

    int n_query, n_course;
    std::cin >> n_query >> n_course;

    std::map<std::string, std::vector<int>> stu_to_course;
    while (n_course--) {
        int course_idx, n_stu;
        std::cin >> course_idx >> n_stu;
        while (n_stu--) {
            std::string stu;
            std::cin >> stu;
            stu_to_course[stu].push_back(course_idx);
        }
    }

    while (n_query--) {
        std::string stu;
        std::cin >> stu;
        std::vector<int> reg_courses = stu_to_course[stu];
        std::sort(reg_courses.begin(), reg_courses.end());
        std::cout << stu  << ' ' << reg_courses.size();
        for (int course_idx : reg_courses) {
            std::cout << ' ' << course_idx;
        }
        std::cout << '\n';
    }

    return 0;
}
