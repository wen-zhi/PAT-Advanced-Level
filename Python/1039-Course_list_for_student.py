from collections import defaultdict


if __name__ == '__main__':
    _, n_course = [int(i) for i in input().split()]
    stu_to_course = defaultdict(list)
    for _ in range(n_course):
        course_idx, n_stu = [int(i) for i in input().split()]
        if n_stu:
            for stu in input().split():
                stu_to_course[stu].append(course_idx)
    for query in input().split():
        print(query,
              len(stu_to_course[query]),
              *sorted(stu_to_course[query]))
