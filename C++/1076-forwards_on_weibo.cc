#include <iostream>
#include <vector>
#include <queue>


using Graph = std::vector<std::vector<int>>;


int maximum_potential_forwards(const Graph &graph, int max_level, int query) {
    int count = 0;
    std::vector<bool> visited(graph.size());
    std::vector<int> dist(graph.size());
    std::queue<int> queue;
    visited[query] = true;
    queue.push(query);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (auto &v : graph[u]) {
            if (!visited[v]) {
                dist[v] = dist[u] + 1;
                if (dist[v] < max_level) {
                    ++count;
                    queue.push(v);
                } else if (dist[v] == max_level) {
                    ++count;
                }
                visited[v] = true;
            }
        }
    }
    return count;
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_node, max_level;
    std::cin >> n_node >> max_level;

    Graph graph(n_node + 1);
    for (int u=1; u<=n_node; ++u) {
        int n_following;
        std::cin >> n_following;
        while (n_following--) {
            int v;
            std::cin >> v;
            graph[v].push_back(u);
        }
    }

    int n_query;
    std::cin >> n_query;
    while (n_query--) {
        int query;
        std::cin >> query;
        std::cout << maximum_potential_forwards(graph, max_level, query) << '\n';
    }

    return 0;
}
