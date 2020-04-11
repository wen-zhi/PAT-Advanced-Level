

def to_nary(decimal, radix=13):
    if decimal == 0:
        return '00'

    res = []
    while decimal != 0:
        decimal, digit = divmod(decimal, radix)
        if digit < 10:
            res.append(str(digit))
        else:
            res.append(chr(digit + 55))
    if len(res) != 2:
        res.append('0')
    return ''.join(reversed(res))


def color_in_mars(r, g, b):
    return '#' + ''.join(to_nary(i) for i in [r, g, b])


if __name__ == '__main__':
    r, g, b = [int(i) for i in input().split()]
    print(color_in_mars(r, g, b))
