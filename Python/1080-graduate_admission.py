

class School():
    def __init__(self, quota):
        self.quota = quota
        self.admitted = []

    def accept(self, applicant):
        if (len(self.admitted) < self.quota or
                applicant == self.admitted[-1]):
            self.admitted.append(applicant)
            return True
        else:
            return False

    def __str__(self):
        return ' '.join(str(applicant.no)
                        for applicant in sorted(self.admitted,
                                                key=lambda x: x.no))


class Applicant():
    def __init__(self, no, G_e, G_i, preferred_schools):
        self.no = no
        self.G_e = G_e
        self.G_i = G_i
        self.preferred_schools = preferred_schools
        self.final_grade = G_e + G_i  # no need to /2

    def __lt__(self, other):
        if self.final_grade < other.final_grade:
            return True
        elif self.final_grade > other.final_grade:
            return False
        return self.G_e < other.G_e

    def __eq__(self, other):
        return (self.final_grade == other.final_grade and
                self.G_e == other.G_e)


if __name__ == '__main__':
    n_applicant, n_school, n_perfer = [int(i) for i in input().split()]
    schools = []
    for quota in input().split():
        schools.append(School(int(quota)))
    applicants = []
    for no in range(n_applicant):
        G_e, G_i, *preferred_schools = [int(i) for i in input().split()]
        applicants.append(Applicant(no, G_e, G_i, preferred_schools))
    applicants.sort(reverse=True)
    for applicant in applicants:
        for school_idx in applicant.preferred_schools:
            if schools[school_idx].accept(applicant):
                break
    for school in schools:
        print(school)
