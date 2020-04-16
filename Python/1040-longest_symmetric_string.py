from collections import namedtuple, deque


Substr = namedtuple('Substr', ['start', 'end'])


def longest_symmetric_string(s):
    queue = deque()
    # odd substr
    for i in range(len(s)):
        queue.append(Substr(i, i))
    # even substr
    for i in range(len(s) - 1):
        if s[i] == s[i+1]:
            queue.append(Substr(i, i+1))
    while queue:
        substr = queue.popleft()
        if (substr.start > 0 and substr.end < len(s) - 1 and
                s[substr.start-1] == s[substr.end+1]):
            queue.append(Substr(substr.start-1, substr.end+1))
    return substr


if __name__ == '__main__':
    s = input()
    start, end = longest_symmetric_string(s)
    print(end - start + 1)
