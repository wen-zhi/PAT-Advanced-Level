

def get_inorder_idx(node_idx, n_node):
    if node_idx >= n_node:
        return []
    return (get_inorder_idx(node_idx * 2 + 1, n_node) + [node_idx] +
            get_inorder_idx(node_idx * 2 + 2, n_node))


if __name__ == '__main__':
    n_node = int(input())
    inorder = sorted(int(i) for i in input().split())
    inorder_idx = get_inorder_idx(0, n_node)
    tree = [None] * n_node
    for idx, value in zip(inorder_idx, inorder):
        tree[idx] = value
    print(*tree)
