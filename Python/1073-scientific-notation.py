

def sci_to_normal(num_sci):
    ans = ''
    if num_sci[0] == '-':
        ans = '-'
    for i, c in enumerate(reversed(num_sci), start=1):
        if c == 'E':
            E_pos = len(num_sci) - i
            break
    expo_sign = num_sci[E_pos + 1]
    expo = int(num_sci[E_pos + 2:])
    figures = num_sci[1] + num_sci[3:E_pos]
    if expo_sign == '-':
        if expo > 0:
            ans += '0.{}{}'.format('0' * (expo - 1), figures)
        else:
            ans = num_sci[:E_pos]
    else:
        expo += 1
        if expo < len(figures):
            ans += figures[:expo] + '.' + figures[expo:]
        else:
            ans += figures + '0' * (expo - len(figures))
    return ans


if __name__ == '__main__':
    num_sci = input()
    print(sci_to_normal(num_sci))
