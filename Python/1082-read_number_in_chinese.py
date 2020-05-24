

digit_to_hanzi = ['ling', 'yi', 'er', 'san', 'si',
                  'wu', 'liu', 'qi', 'ba', 'jiu']
pos_to_thousands = ['', 'Shi', 'Bai', 'Qian', 'Wan',
                    'Shi', 'Bai', 'Qian', 'Yi']


def reading_number(n):
    if n == 0:
        return 'ling'
    n = str(n)
    if n[0] == '-':
        sign = 'Fu '
        n = n[1:]
    else:
        sign = ''
    res = []
    zeros = 0
    for i, digit in enumerate(n, start=1):
        pos = len(n) - i  # counting from right
        if digit != '0':
            if zeros > 0:
                res.append('ling')
            res.append(digit_to_hanzi[int(digit)])
            if pos > 0:  # no need to output '个'位
                res.append(pos_to_thousands[pos])
            zeros = 0
        else:
            zeros += 1
            if pos == 4 and zeros < 4:  # handling numbers like '100001'
                res.append('Wan')
    return sign + ' '.join(res)


if __name__ == '__main__':
    n = int(input())
    print(reading_number(n))
