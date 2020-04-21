from collections import deque


def check_pop_sequence(seq, stack_size, n_elem):
    seq_q = deque(seq)
    stack = []
    for elem in range(1, n_elem + 1):
        while elem > seq_q[0]:
            if stack and stack.pop() == seq_q[0]:
                seq_q.popleft()
            else:
                break
        if elem < seq_q[0]:
            if len(stack) < stack_size - 1:
                stack.append(elem)
                continue
            else:
                break
        if elem == seq_q[0]:
            seq_q.popleft()
        else:
            break
    while stack:
        if stack.pop() == seq_q[0]:
            seq_q.popleft()
        else:
            break
    if seq_q:
        return "NO"
    else:
        return "YES"


if __name__ == '__main__':
    stack_size, n_elem, n_seq = [int(i) for i in input().split()]
    for _ in range(n_seq):
        seq = [int(i) for i in input().split()]
        print(check_pop_sequence(seq, stack_size, n_elem))
