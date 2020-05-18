#include <iostream>
#include <vector>
#include <algorithm>


struct Applicant {
    Applicant() = default;
    Applicant(int no, int G_e, int G_i):
        no(no), G_e(G_e), G_i(G_i), final_grade(G_e + G_i) {}
    int no, G_e, G_i, final_grade;
    std::vector<int> preferred_schools;
};


struct School {
    School() = default;
    School(std::size_t quota): quota(quota) {}
    std::size_t quota;
    std::vector<Applicant> admitted;
    bool accept(Applicant applicant);
};


bool operator<(const Applicant &a1, const Applicant &a2) {
    if (a1.final_grade < a2.final_grade) {
        return true;
    } else if (a1.final_grade > a2.final_grade) {
        return false;
    }
    return a1.G_e < a2.G_e;
}


bool operator==(const Applicant &a1, const Applicant &a2) {
    return a1.final_grade == a2.final_grade &&
           a1.G_e == a2.G_e;
}


bool School::accept(Applicant applicant) {
    if (admitted.size() < quota || applicant == admitted.back()) {
        admitted.push_back(applicant);
        return true;
    } else {
        return false;
    }
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_applicant, n_school, n_prefer;
    std::cin >> n_applicant >> n_school >> n_prefer;
    std::vector<School> schools;
    while (n_school--) {
        std::size_t quota;
        std::cin >> quota;
        schools.push_back(School(quota));
    }
    std::vector<Applicant> applicants;
    for (int i=0; i<n_applicant; ++i) {
        int G_e, G_i;
        std::cin >> G_e >> G_i;
        Applicant applicant(i, G_e, G_i);
        for (int j=0; j<n_prefer; ++j) {
            int school;
            std::cin >> school;
            applicant.preferred_schools.push_back(school);
        }
        applicants.push_back(applicant);
    }
    std::sort(applicants.rbegin(), applicants.rend());
    for (auto &applicant : applicants) {
        for (auto &school : applicant.preferred_schools) {
            if (schools[school].accept(applicant))
                break;
        }
    }
    for (auto &school : schools) {
        auto admitted = school.admitted;
        std::sort(admitted.begin(), admitted.end(),
                  [](const Applicant &a1, const Applicant &a2)
                     {return a1.no < a2.no;});
        for (std::size_t i=0; i!=admitted.size(); ++i) {
            if (i > 0) std::cout << ' ';
            std::cout << admitted[i].no;
        }
        std::cout << '\n';
    }

    return 0;
}
