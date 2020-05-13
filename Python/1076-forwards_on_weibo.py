from collections import deque


def maximum_potential_forwards(query, graph, max_level):
    count = 0
    visited = [False] * len(graph)
    dist = [0] * len(graph)
    visited[query] = True
    queue = deque([query])
    while queue:
        u = queue.popleft()
        for v in graph[u]:
            if visited[v] is False:
                dist[v] = dist[u] + 1
                if dist[v] < max_level:
                    count += 1
                    queue.append(v)
                elif dist[v] == max_level:
                    count += 1
                visited[v] = True
    return count


if __name__ == '__main__':
    n_node, max_level = [int(i) for i in input().split()]
    graph = [[] for _ in range(n_node + 1)]
    for u in range(1, n_node + 1):
        user_list = [int(i) for i in input().split()][1:]
        for v in user_list:
            graph[v].append(u)
    query_list = [int(i) for i in input().split()][1:]
    for query in query_list:
        print(maximum_potential_forwards(query, graph, max_level))
