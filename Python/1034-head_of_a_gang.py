from collections import defaultdict, deque


def head_of_gang(graph, thre, edge_weights, head_weights):
    def bfs(vertex):
        max_h_weight, head = 0, None
        n_member, total_weight = 0, 0
        queue = deque([vertex])
        visited[vertex] = True
        while queue:
            u = queue.popleft()
            n_member += 1
            if head_weights[u] > max_h_weight:
                head = u
                max_h_weight = head_weights[u]
            for v in graph[u]:
                total_weight += edge_weights[(u, v)]
                if visited[v] is False:
                    queue.append(v)
                    visited[v] = True
        if n_member > 2 and total_weight > thre:
            return head, n_member
        else:
            return None
    heads = []
    visited = defaultdict(bool)
    for people in graph:
        if visited[people] is False:
            head = bfs(people)
            if head:
                heads.append(head)
    return sorted(heads)


if __name__ == '__main__':
    n_call, thre = [int(i) for i in input().split()]
    graph = defaultdict(set)
    head_weights = defaultdict(int)
    edge_weights = defaultdict(int)
    for _ in range(n_call):
        u, v, w = input().split()
        w = int(w)
        graph[u].add(v)
        graph[v].add(u)
        head_weights[u] += w
        head_weights[v] += w
        edge_weights[(u, v)] = w
    heads = head_of_gang(graph, thre, edge_weights, head_weights)
    print(len(heads))
    for head, n_member in heads:
        print(head, n_member)
