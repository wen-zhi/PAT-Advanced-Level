

def longest_stripe(given_stripe, favorite_color):
    given_stripe = [i for i in given_stripe if i in set(favorite_color)]
    color_order = {}
    for i, color in enumerate(favorite_color):
        color_order[color] = i
    L = [0] * len(given_stripe)
    for j in range(len(given_stripe)):
        max_len = 1
        for i in range(j):
            if color_order[given_stripe[i]] <= color_order[given_stripe[j]]:
                max_len = max(max_len, L[i] + 1)
        L[j] = max_len
    return L[-1]


if __name__ == '__main__':
    _ = input()
    favorite_color = [int(i) for i in input().split()][1:]
    given_stripe = [int(i) for i in input().split()][1:]
    print(longest_stripe(given_stripe, favorite_color))
