

if __name__ == '__main__':
    seq1 = [int(i) for i in input().split()][1:]
    seq2 = [int(i) for i in input().split()][1:]
    seq = seq1 + seq2
    seq.sort()
    print(seq[(len(seq) - 1) // 2])


# from collections import deque


# def median(seq_a, seq_b):
#     seq_a, seq_b = deque(seq_a), deque(seq_b)
#     mid_pos = (len(seq_a) + len(seq_b) + 1) // 2
#     pos = 0
#     while seq_a and seq_b:
#         if seq_a[0] < seq_b[0]:
#             num = seq_a.popleft()
#         else:
#             num = seq_b.popleft()
#         pos += 1
#         if pos == mid_pos:
#             return num
#     if seq_a:
#         return seq_a[mid_pos - pos - 1]
#     if seq_b:
#         return seq_b[mid_pos - pos - 1]


# if __name__ == '__main__':
#     seq_a = [int(i) for i in input().split()][1:]
#     seq_b = [int(i) for i in input().split()][1:]
#     print(median(seq_a, seq_b))
