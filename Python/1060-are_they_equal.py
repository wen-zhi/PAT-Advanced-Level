

def to_standard_form(num: str, precision: int) -> str:
    num = num.lstrip('0')
    if num.startswith('.'):  # fraction
        num = num[1:]
        k = len(num.lstrip('0')) - len(num)
        num = num.lstrip('0')
        if not num:
            k = 0
    else:  # non-fraction
        dot_pos = num.find('.')
        k = dot_pos if dot_pos > 0 else len(num)
        num = num.replace('.', '')
    if precision > len(num):
        num += (precision - len(num)) * '0'
    else:
        num = num[:precision]
    return f'0.{num}*10^{k}'


if __name__ == '__main__':
    precision, n1, n2 = input().split()
    precision = int(precision)
    n1_std = to_standard_form(n1, precision)
    n2_std = to_standard_form(n2, precision)
    if n1_std == n2_std:
        print("YES", n1_std)
    else:
        print("NO", n1_std, n2_std)
