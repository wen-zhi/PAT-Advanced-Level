

class BITree():
    def __init__(self, size):
        self.size = size
        self._bitree = [0] * (self.size + 1)

    def __getitem__(self, pos):
        return self._bitree[pos]

    def get_sum(self, pos):
        res = 0
        while pos > 0:
            res += self._bitree[pos]
            pos -= (pos & (-pos))
        return res

    def update(self, pos, value):
        while pos <= self.size:
            self._bitree[pos] += value
            pos += (pos & (-pos))


class Stack():
    def __init__(self):
        self.data = []
        self.bitree = BITree(100000)

    def empty(self):
        return len(self.data) == 0

    def push(self, value):
        self.data.append(value)
        self.bitree.update(value, 1)

    def pop(self):
        value = self.data.pop()
        self.bitree.update(value, -1)
        return value

    def peekmedian(self):
        target_freq = (len(self.data) + 1) // 2
        low, high = 1, 100000
        while low <= high:
            mid = (low + high) // 2
            if self.bitree.get_sum(mid) < target_freq:
                low = mid + 1
            else:
                high = mid - 1
        return low


if __name__ == '__main__':
    n_ops = int(input())
    stack = Stack()
    for _ in range(n_ops):
        line = input()
        if line[:4] == 'Push':
            _, value = line.split()
            stack.push(int(value))
        elif not stack.empty():
            if line[:3] == 'Pop':
                print(stack.pop())
            else:
                print(stack.peekmedian())
        else:
            print("Invalid")
