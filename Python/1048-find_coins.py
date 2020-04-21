

def find_coins(coins, amount):
    memo = set()
    solutions = []
    for v1 in coins:
        v2 = amount - v1
        if v2 in memo:
            solutions.append(sorted([v1, v2]))
        memo.add(v1)
    return solutions


if __name__ == '__main__':
    _, amount = [int(i) for i in input().split()]
    coins = [int(i) for i in input().split()]
    solutions = find_coins(coins, amount)
    if solutions:
        print(*min(solutions))
    else:
        print("No Solution")
