

def check_pop_sequence(seq, stack_size):
    stack = []
    elem = 1
    is_popseq = True
    for num in seq:
        while elem <= num:
            if len(stack) < stack_size:
                stack.append(elem)
                elem += 1
            else:
                is_popseq = False
                break
        if stack.pop() != num:
            is_popseq = False
            break
    if is_popseq:
        return "YES"
    else:
        return "NO"


if __name__ == '__main__':
    stack_size, _, n_seq = [int(i) for i in input().split()]
    for _ in range(n_seq):
        seq = [int(i) for i in input().split()]
        print(check_pop_sequence(seq, stack_size))
