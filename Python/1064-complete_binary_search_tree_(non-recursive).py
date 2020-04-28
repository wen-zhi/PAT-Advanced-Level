

def get_inorder_idx(n_node):
    """non-recursive inorder taversal."""
    res = []
    stack = []
    node = 0
    while True:
        while node < n_node:
            stack.append(node)
            node = node * 2 + 1  # lchild
        while stack:
            node = stack.pop()
            res.append(node)
            rchild = node * 2 + 2
            if rchild < n_node:
                node = rchild
                break
        else:
            break
    return res


if __name__ == '__main__':
    n_node = int(input())
    inorder = sorted(int(i) for i in input().split())
    inorder_idx = get_inorder_idx(n_node)
    tree = [None] * n_node
    for idx, value in zip(inorder_idx, inorder):
        tree[idx] = value
    print(*tree)
