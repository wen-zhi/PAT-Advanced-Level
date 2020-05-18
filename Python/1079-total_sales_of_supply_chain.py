from collections import deque


def total_sales(graph, sink_nodes, unit_price, rate):
    if len(graph) == 1:
        return unit_price * graph[0][0]
    ans = 0.
    rate /= 100
    price = [0.] * len(graph)
    price[0] = unit_price
    queue = deque([0])
    while queue:
        u = queue.popleft()
        for v in graph[u]:
            price[v] = price[u] * (1 + rate)
            if v not in sink_nodes:
                queue.append(v)
            else:
                ans += price[v] * graph[v][0]
    return ans


if __name__ == '__main__':
    n_node, unit_price, rate = [float(i) for i in input().split()]
    n_node = int(n_node)
    graph = [None] * n_node
    sink_nodes = set()
    for i in range(n_node):
        count, *adj_nodes = [int(i) for i in input().split()]
        if count == 0:
            sink_nodes.add(i)
        graph[i] = adj_nodes
    print(f'{total_sales(graph, sink_nodes, unit_price, rate):.1f}')
