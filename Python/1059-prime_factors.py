from collections import Counter


PRIMES = set()


def factorize(num):
    if num in PRIMES:
        RES[num] += 1
        return
    i = 2
    while i * i <= num:
        if num % i == 0:
            factorize(i)
            factorize(num // i)
            return
        i += 1
    PRIMES.add(num)
    RES[num] += 1


if __name__ == '__main__':
    num = int(input())
    RES = Counter()
    factorize(num)
    ans = []
    for key in sorted(RES.keys()):
        expo = RES[key]
        if expo > 1:
            ans.append(f'{key}^{expo}')
        else:
            ans.append(str(key))
    print(num, '=', '*'.join(ans), sep='')
