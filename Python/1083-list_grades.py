from operator import attrgetter


class Student():
    def __init__(self, name, ID, grade):
        self.name = name
        self.ID = ID
        self.grade = grade

    def __str__(self):
        return f'{self.name} {self.ID}'


def students_in_given_grade_range(students, bgn_grade, end_grade):
    def lower_bound(grade):
        low, high = 0, len(students) - 1
        while low <= high:
            mid = (low + high) // 2
            if students[mid].grade > grade:
                low = mid + 1
            elif students[mid].grade < grade:
                high = mid - 1
            else:
                return mid
        return low

    def upper_bound(grade):
        low, high = 0, len(students) - 1
        while low <= high:
            mid = (low + high) // 2
            if students[mid].grade >= grade:
                low = mid + 1
            elif students[mid].grade < grade:
                high = mid - 1
        return low
    students = sorted(students, key=attrgetter('grade'), reverse=True)
    lower = lower_bound(end_grade)
    upper = upper_bound(bgn_grade)
    return students[lower:upper]


if __name__ == '__main__':
    n_student = int(input())
    students = []
    for _ in range(n_student):
        name, ID, grade = input().split()
        students.append(Student(name, ID, int(grade)))
    bgn_grade, end_grade = [int(i) for i in input().split()]
    res = students_in_given_grade_range(students, bgn_grade, end_grade)
    if res:
        for student in res:
            print(student)
    else:
        print("NONE")
