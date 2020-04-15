

REPLACE_DICT = {
    '1': '@',
    '0': '%',
    'l': 'L',
    'O': 'o'
}


def modify_passwd(passwd):
    new_passwd = []
    is_modified = False
    for c in passwd:
        try:
            new_passwd.append(REPLACE_DICT[c])
            is_modified = True
        except KeyError:
            new_passwd.append(c)
    if is_modified:
        return ''.join(new_passwd)
    else:
        return ''


if __name__ == '__main__':
    n_user = int(input())
    modified = []
    for _ in range(n_user):
        name, passwd = input().split()
        new_passwd = modify_passwd(passwd)
        if new_passwd:
            modified.append((name, new_passwd))
    if modified:
        print(len(modified))
        for name, passwd in modified:
            print(name, passwd)
    else:
        if n_user > 1:
            account = f'are {n_user} accounts'
        else:
            account = 'is 1 account'
        print(f'There {account} and no account is modified')
