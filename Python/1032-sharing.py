from collections import defaultdict


def common_prefix(word_a, word_b, nexts):
    visited = defaultdict(int)
    while word_a != "-1":
        visited[word_a] = 1
        word_a = nexts[word_a]
    while word_b != "-1":
        if visited[word_b]:
            return word_b
        word_b = nexts[word_b]
    return -1


if __name__ == '__main__':
    word_a, word_b, n_node = input().split()
    nexts = {}
    for _ in range(int(n_node)):
        addr, _, nxt = input().split()
        nexts[addr] = nxt
    print(common_prefix(word_a, word_b, nexts))
