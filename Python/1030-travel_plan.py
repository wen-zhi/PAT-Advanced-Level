import heapq


def shortest_path(graph, src, dst):
    dist = [float('inf')] * len(graph)
    dist[src] = 0
    cost = [float('inf')] * len(graph)
    cost[src] = 0
    pre = [None] * len(graph)

    queue = [(dist[src], src)]
    while queue:
        _, u = heapq.heappop(queue)
        for v, d, c in graph[u]:
            alt_dist = dist[u] + d
            alt_cost = cost[u] + c
            if alt_dist < dist[v]:
                dist[v] = alt_dist
                cost[v] = alt_cost
                pre[v] = u
                heapq.heappush(queue, (dist[v], v))
            elif alt_dist == dist[v]:
                if alt_cost < cost[v]:
                    cost[v] = alt_cost
                    pre[v] = u
                    heapq.heappush(queue, (dist[v], v))

    parent = dst
    path = [parent]
    while pre[parent] is not None:
        parent = pre[parent]
        path.append(parent)

    return path[::-1], dist[dst], cost[dst]


if __name__ == '__main__':
    n_city, n_highway, src, dst = [int(i) for i in input().split()]
    graph = [[] for _ in range(n_city)]
    for _ in range(n_highway):
        u, v, d, c = [int(i) for i in input().split()]
        graph[u].append((v, d, c))
        graph[v].append((u, d, c))
    path, min_dist, min_cost = shortest_path(graph, src, dst)
    print(*path, min_dist, min_cost)
