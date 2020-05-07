import re
from collections import Counter


def most_common_word(text):
    counter = Counter(word.lower()
                      for word in re.findall(r'[a-zA-Z0-9]+', text))
    the_word = min(counter.items(), key=lambda x: (-x[1], x[0]))
    return the_word


if __name__ == '__main__':
    text = input()
    print(*most_common_word(text))
