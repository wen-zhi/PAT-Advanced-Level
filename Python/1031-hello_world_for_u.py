

def convert_to_U(s):
    n1 = (len(s) + 2) // 3
    n2 = (len(s) + 2) - 2 * n1
    res = []
    for i in range(n1 - 1):
        res.append(s[i] + ' ' * (n2 - 2) + s[-i-1])
    res.append(s[i+1:-i-1])
    return '\n'.join(res)


if __name__ == '__main__':
    s = input()
    print(convert_to_U(s))
