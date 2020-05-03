

class Node():
    def __init__(self):
        self.value = 0
        self.is_used = False


def find_coins(coins, total_amount):
    coins = sorted(coins, reverse=True)
    # shape: (total_amount + 1, len(coins) + 1)
    M = [[Node() for _ in range(len(coins) + 1)]
         for _ in range(total_amount + 1)]
    for v in range(1, total_amount + 1):
        for j, coin in enumerate(coins, start=1):
            if coin <= v:
                alt_v = M[v-coin][j-1].value + coin
                if alt_v >= M[v][j-1].value:
                    M[v][j].value = alt_v
                    M[v][j].is_used = True
                else:
                    M[v][j].value = M[v][j-1].value
                    M[v][j].is_used = False
            else:
                M[v][j].value = M[v][j-1].value
                M[v][j].is_used = False
    path = []
    if M[v][j].value == total_amount:
        while j > 0:
            if M[v][j].is_used:
                path.append(coins[j-1])  # idx start from 0
                v -= coins[j-1]
            j -= 1
    return path


if __name__ == '__main__':
    _, total_amount = [int(i) for i in input().split()]
    coins = [int(i) for i in input().split()]
    solution = find_coins(coins, total_amount)
    if solution:
        print(*solution)
    else:
        print("No Solution")
