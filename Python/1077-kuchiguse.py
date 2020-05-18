import sys


def kuchiguse(sentences):
    min_len = min(len(sentence) for sentence in sentences)
    start_pos = 0
    for i in range(-1, -(min_len+1), -1):
        if len(set(sentence[i] for sentence in sentences)) == 1:
            start_pos = i
        else:
            break
    if start_pos < 0:
        return sentences[0][start_pos:]
    else:
        return "nai"


if __name__ == '__main__':
    sentences = sys.stdin.read().strip().split('\n')[1:]
    print(kuchiguse(sentences))
