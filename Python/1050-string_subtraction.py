

if __name__ == '__main__':
    s1 = input()
    s2 = input()
    res = ''.join(c for c in s1 if c not in set(s2))
    print(res)
