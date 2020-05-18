

class HashTable():

    def __init__(self, given_size):
        self.table_size = self._next_prime(given_size)
        self.data = [None] * self.table_size
        self.size = 0

    def insert(self, value):
        idx = '-'
        if self.size < self.table_size:
            i = 0
            max_i = self.table_size // 2
            while i <= max_i:
                pos = (value + i ** 2) % self.table_size
                if self.data[pos] is None:
                    idx = pos
                    self.data[idx] = value
                    self.size += 1
                    break
                i += 1
        return idx

    def _next_prime(self, given_size):
        from math import sqrt
        nxt = given_size
        if nxt < 3:
            return 2
        if nxt % 2 == 0:
            nxt += 1
        while True:
            i = int(sqrt(nxt))
            while i > 2:
                if nxt % i == 0:
                    break
                else:
                    i -= 1
            else:
                break
            nxt += 2
        return nxt


def get_hashing_indices(nums, max_size):
    hash_table = HashTable(max_size)
    return [hash_table.insert(num)
            for num in nums]


if __name__ == '__main__':
    max_size, _ = [int(i) for i in input().split()]
    nums = [int(i) for i in input().split()]
    print(*get_hashing_indices(nums, max_size))
