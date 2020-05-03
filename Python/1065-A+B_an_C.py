

if __name__ == '__main__':
    n_test_case = int(input())
    for i in range(1, n_test_case + 1):
        a, b, c = [int(i) for i in input().split()]
        print(f'Case #{i}:', end=' ')
        if a + b > c:
            print('true')
        else:
            print('false')
