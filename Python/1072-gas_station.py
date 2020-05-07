from math import inf
import heapq


def Dijkstra(graph, src):
    dist = [inf] * len(graph)
    dist[src] = 0
    queue = [(dist[src], src)]
    while queue:
        _, u = heapq.heappop(queue)
        for v, w in graph[u]:
            alt_dist = dist[u] + w
            if alt_dist < dist[v]:
                dist[v] = alt_dist
                heapq.heappush(queue, (dist[v], v))
    return dist


def choose_gas_station(graph, n_house, n_gas_station, max_range):
    max_min_dist, min_avg_dist = -inf, inf
    best_gas_station = None
    for i in range(1, n_gas_station + 1):
        gas_station = n_house + i
        dist = Dijkstra(graph, gas_station)
        min_dist, dist_sum = inf, 0
        for house in range(1, n_house + 1):
            dist_to_house = dist[house]
            if dist_to_house > max_range:
                break
            if dist_to_house < min_dist:
                min_dist = dist_to_house
            dist_sum += dist_to_house
        else:
            avg_dist = dist_sum / house
            if min_dist > max_min_dist:
                max_min_dist = min_dist
                min_avg_dist = avg_dist
                best_gas_station = f'G{i}'
            elif min_dist == max_min_dist:
                if avg_dist < min_avg_dist:
                    min_avg_dist = avg_dist
                    best_gas_station = f'G{i}'
    return best_gas_station, max_min_dist, min_avg_dist


if __name__ == '__main__':
    n_house, n_gas_station, n_edge, max_range = [
        int(i) for i in input().split()]
    graph = [[] for _ in range(n_house + n_gas_station + 1)]
    for _ in range(n_edge):
        u, v, w = input().split()
        if u[0] == 'G':
            u = n_house + int(u[1:])
        else:
            u = int(u)
        if v[0] == 'G':
            v = n_house + int(v[1:])
        else:
            v = int(v)
        w = int(w)
        graph[u].append((v, w))
        graph[v].append((u, w))
    gas_station, min_dist, avg_dist = choose_gas_station(
        graph, n_house, n_gas_station, max_range)
    if gas_station:
        print(gas_station)
        # avg_dist = int(avg_dist * 10 + 0.5) / 10  # round half
        print(f'{min_dist:.1f} {avg_dist:.1f}')
    else:
        print('No Solution')
