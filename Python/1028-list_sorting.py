from operator import attrgetter


class Student():
    def __init__(self, id, name, grade):
        self.id = id
        self.name = name
        self.grade = grade

    def __str__(self):
        return f'{self.id} {self.name} {self.grade}'


def sort_by_col(students, col=1):
    """sort students with col in-place."""
    if col == 1:
        students.sort(key=attrgetter("id"))
    elif col == 2:
        students.sort(key=attrgetter("name", "id"))
    elif col == 3:
        students.sort(key=attrgetter("grade", "id"))


if __name__ == '__main__':
    n_student, col = [int(i) for i in input().split()]
    students = []
    for _ in range(n_student):
        id, name, grade = input().split()
        students.append(Student(id, name, grade))
    sort_by_col(students, col)
    for student in students:
        print(student)
