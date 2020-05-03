

class Node():
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1


class AVLTree():
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert(self.root, key)

    def _insert(self, node, key):
        if node is None:
            return Node(key)
        if key > node.key:
            node.right = self._insert(node.right, key)
        elif key < node.key:
            node.left = self._insert(node.left, key)
        node.height = 1 + max(self._height(node.left),
                              self._height(node.right))
        # balance
        balance_factor = self._height(node.left) - self._height(node.right)
        if balance_factor > 1:
            if key > node.left.key:
                node.left = self._left_rotate(node.left)
            node = self._right_rotate(node)
        elif balance_factor < -1:
            if key < node.right.key:
                node.right = self._right_rotate(node.right)
            node = self._left_rotate(node)
        return node

    def _height(self, node):
        if node is None:
            return 0
        return node.height

    def _left_rotate(self, node):
        head = node.right
        node.right = head.left
        head.left = node
        node.height = 1 + max(self._height(node.left),
                              self._height(node.right))
        head.height = 1 + max(self._height(head.left),
                              self._height(head.right))
        return head

    def _right_rotate(self, node):
        head = node.left
        node.left = head.right
        head.right = node
        node.height = 1 + max(self._height(node.left),
                              self._height(node.right))
        head.height = 1 + max(self._height(head.left),
                              self._height(head.right))
        return head


if __name__ == '__main__':
    _ = input()
    keys = [int(i) for i in input().split()]
    T = AVLTree()
    for key in keys:
        T.insert(key)
    print(T.root.key)
