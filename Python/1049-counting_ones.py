

def number_of_one(num):
    ones = 0
    base = 1
    while base <= num:
        right = num % base
        left = num // (base * 10)
        digit = num // base % 10
        if digit == 0:
            ones += left * base
        elif digit == 1:
            ones += left * base + right + 1
        else:
            ones += (left + 1) * base
        base *= 10
    return ones


if __name__ == '__main__':
    num = int(input())
    print(number_of_one(num))
