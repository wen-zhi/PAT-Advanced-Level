from collections import deque


def recover_path(pre, u):
    path = [WEIGHTS[u]]
    while pre[u] is not None:
        u = pre[u]
        path.append(WEIGHTS[u])
    return path[::-1]


def path_of_equal_weight(graph, target_w):
    visited = [False] * len(graph)
    pre = [None] * n_node
    path_weights = [0] * len(graph)
    path_weights[0] = WEIGHTS[0]
    queue = deque([0])
    # BFS:
    while queue:
        u = queue.popleft()
        visited[u] = True
        if path_weights[u] > target_w:  # pruning
            continue
        for v in graph[u]:
            if visited[v] is False:
                path_weights[v] = path_weights[u] + WEIGHTS[v]
                pre[v] = u
                queue.append(v)
    paths = []
    for u in range(len(graph)):
        if not graph[u] and path_weights[u] == target_w:
            paths.append(recover_path(pre, u))
    paths.sort(reverse=True)
    return paths


if __name__ == '__main__':
    n_node, n_nonleaf, target_w = [int(i) for i in input().split()]
    WEIGHTS = [int(i) for i in input().split()]
    graph = [[] for _ in range(n_node)]
    for _ in range(n_nonleaf):
        u, _, *adj_list = [int(i) for i in input().split()]
        graph[u] = adj_list
    paths = path_of_equal_weight(graph, target_w)
    for path in paths:
        print(*path)
