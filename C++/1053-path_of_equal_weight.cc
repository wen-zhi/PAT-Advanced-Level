#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using Graph = std::vector<std::vector<int>>;
std::vector<int> weights;


std::vector<int> recover_path(std::vector<int> &pre, int u) {
    std::vector<int> path{weights[u]};
    while (pre[u] != -1) {
        u = pre[u];
        path.push_back(weights[u]);
    }
    std::reverse(path.begin(), path.end());
    return path;
}


std::vector<std::vector<int>>
path_of_equal_weight(Graph &graph, int target_w)
{
    std::vector<bool> visited(graph.size());
    std::vector<int> pre(graph.size(), -1);
    std::vector<int> path_weights(graph.size());
    path_weights[0] = weights[0];
    std::queue<int> Queue;
    Queue.push(0);
    while (!Queue.empty()) {
        int u = Queue.front();
        Queue.pop();
        visited[u] = true;
        if (path_weights[u] > target_w) {
            continue;   // pruning
        }
        for (auto v : graph[u]) {
            if (!visited[v]) {
                path_weights[v] = path_weights[u] + weights[v];
                pre[v] = u;
                Queue.push(v);
            }
        }
    }
    std::vector<std::vector<int>> paths;
    for (std::size_t u=0; u!=graph.size(); ++u) {
        if (graph[u].empty() && path_weights[u] == target_w) {
            paths.push_back(recover_path(pre, u));
        }
    }
    std::sort(paths.rbegin(), paths.rend());
    return paths;
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_node, n_nonleaf, target_w;
    std::cin >> n_node >> n_nonleaf >> target_w;

    for (int i=0; i<n_node; ++i) {
        int weight;
        std::cin >> weight;
        weights.push_back(weight);
    }

    Graph graph(n_node);
    for (int i=0; i<n_nonleaf; ++i) {
        int u, n_neighbor;
        std::cin >> u >> n_neighbor;
        while (n_neighbor--) {
            int v;
            std::cin >> v;
            graph[u].push_back(v); 
        }
    }

    std::vector<std::vector<int>> paths = path_of_equal_weight(graph, target_w);
    for (auto &path : paths) {
        for (std::size_t i=0; i!=path.size()-1; ++i) {
            std::cout << path[i] << ' ';
        }
        std::cout << path.back() << '\n';
    }

    return 0;
}
