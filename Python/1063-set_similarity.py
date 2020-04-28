

if __name__ == '__main__':
    n_set = int(input())
    sets = []
    for _ in range(n_set):
        sets.append(set([int(i) for i in input().split()][1:]))

    n_query = int(input())
    for _ in range(n_query):
        a, b = [int(i) - 1 for i in input().split()]
        n_c = len(sets[a] & sets[b])
        n_t = len(sets[a]) + len(sets[b]) - n_c
        similarity = n_c / n_t
        print(f'{similarity:.1%}')
