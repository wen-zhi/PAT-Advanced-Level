from collections import namedtuple


Solution = namedtuple('Solution', ['bgn', 'end'])


def shopping_in_mars(diamonds, amount):
    solutions = []
    bgn = end = 0
    p_sum = 0
    nearest_amount = float('inf')
    while end < len(diamonds):
        while end < len(diamonds) and p_sum < amount:
            p_sum += diamonds[end]
            end += 1
        while p_sum >= amount:
            if p_sum == amount:
                solutions.append(Solution(bgn, end - 1))
            else:
                if p_sum < nearest_amount:
                    nearest_amount = p_sum
                    nearest_solutions = [Solution(bgn, end - 1)]
                elif p_sum == nearest_amount:
                    nearest_solutions.append(Solution(bgn, end - 1))
            p_sum -= diamonds[bgn]
            bgn += 1
    if solutions:
        return solutions
    else:
        return nearest_solutions


if __name__ == '__main__':
    _, amount = [int(i) for i in input().split()]
    diamonds = [int(i) for i in input().split()]
    solutions = shopping_in_mars(diamonds, amount)
    for bgn, end in solutions:
        print(f'{bgn + 1}-{end + 1}')
