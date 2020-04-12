#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
#include <utility>


struct Edge {
    int node;
    int distance;
    int cost;
};


using Graph = std::vector<std::vector<Edge>>;
using Plan = std::tuple<std::string, int, int>;
const int inf = std::numeric_limits<int>::max();


Plan shortest_path(Graph &graph, int src, int dst) {
    std::vector<int> dist(graph.size(), inf);
    dist[src] = 0;
    std::vector<int> cost(graph.size(), inf);
    cost[src] = 0;
    std::vector<int> pre(graph.size(), -1);

    std::priority_queue<std::pair<int, int>> queue;
    queue.push(std::make_pair(dist[src], src));
    while (!queue.empty()) {
        int u = queue.top().second;
        queue.pop();
        for (Edge &edge : graph[u]) {
            int v = edge.node;
            int alt_dist = dist[u] + edge.distance;
            int alt_cost = cost[u] + edge.cost;
            if (alt_dist < dist[v]) {
                dist[v] = alt_dist;
                cost[v] = alt_cost;
                pre[v] = u;
                queue.push(std::make_pair(dist[v], v));
            } else if (alt_dist == dist[v]) {
                if (alt_cost < cost[v]) {
                    cost[v] = alt_cost;
                    pre[v] = u;
                    queue.push(std::make_pair(dist[v], v));
                }
            }
        }
    }

    std::string path(std::to_string(dst));
    int parent = dst;
    while (pre[parent] != -1) {
        parent = pre[parent];
        path = std::to_string(parent) + std::string(" ") + path;
    }

    return {path, dist[dst], cost[dst]};
}


int main() {

    int n_city, n_highway, src, dst;
    std::cin >> n_city >> n_highway >> src >> dst;

    Graph graph(n_city);
    int u, v, d, c;
    for (int i=0; i<n_highway; ++i) {
        std::cin >> u >> v >> d >> c;
        graph[u].push_back({v, d, c});
        graph[v].push_back({u, d, c});
    }

    auto plan = shortest_path(graph, src, dst);
    std::cout << std::get<0>(plan) << ' '
              << std::get<1>(plan) << ' '
              << std::get<2>(plan) << '\n';

    return 0;
}
