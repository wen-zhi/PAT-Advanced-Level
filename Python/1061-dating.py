import sys


letter_to_day = {
    'A': 'MON',
    'B': 'TUE',
    'C': 'WED',
    'D': 'THU',
    'E': 'FRI',
    'F': 'SAT',
    'G': 'SUN'
}


def decode(strings: str) -> str:
    day_is_found = False
    for first, second in zip(strings[0], strings[1]):
        if first == second:
            if day_is_found is False:
                if 'A' <= first <= 'G':
                    day = letter_to_day[first]
                    day_is_found = True
            else:
                if 'A' <= first <= 'N':
                    hour = ord(first) - ord('A') + 10
                    break
                elif first.isdigit():
                    hour = int(first)
                    break
    for i, (first, second) in enumerate(zip(strings[2], strings[3])):
        if first.isalpha() and second.isalpha() and first == second:
            minute = i
            break
    return f'{day} {hour:02d}:{minute:02d}'


if __name__ == '__main__':
    strings = sys.stdin.read().split()
    print(decode(strings))
