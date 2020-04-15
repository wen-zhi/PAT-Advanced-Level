from collections import namedtuple


Student = namedtuple('Student', ['name', 'id', 'grade'])


if __name__ == '__main__':
    n_student = int(input())
    boys, girls = [], []
    for _ in range(n_student):
        name, gender, id, grade = input().split()
        grade = int(grade)
        if gender == 'F':
            girls.append(Student(name, id, grade))
        else:
            boys.append(Student(name, id, grade))
    top_girl = bottom_boy = None
    if girls:
        top_girl = max(girls, key=lambda x: x.grade)
        print(top_girl.name, top_girl.id)
    else:
        print("Absent")
    if boys:
        bottom_boy = min(boys, key=lambda x: x.grade)
        print(bottom_boy.name, bottom_boy.id)
    else:
        print("Absent")
    if top_girl and bottom_boy:
        print(top_girl.grade - bottom_boy.grade)
    else:
        print("NA")
