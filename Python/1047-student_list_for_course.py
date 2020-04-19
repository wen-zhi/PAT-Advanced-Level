

if __name__ == '__main__':
    n_student, n_course = [int(i) for i in input().split()]
    course_to_student = [[] for _ in range(n_course + 1)]
    for _ in range(n_student):
        name, _, *reg_courses = input().split()
        for course in reg_courses:
            course_to_student[int(course)].append(name)
    for course in range(1, n_course + 1):
        reg_students = course_to_student[course]
        print(course, len(reg_students))
        for student in sorted(reg_students):
            print(student)
