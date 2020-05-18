#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iomanip>


using Graph = std::vector<std::vector<int>>;


double total_sales(const Graph &graph,
                   const std::unordered_set<int> &sink_nodes,
                   double unit_price, double rate)
{
    if (graph.size() == 1) {
        return unit_price * graph[0][0];
    } // only has one node
    double ans = 0.;
    rate /= 100;
    std::vector<double> price(graph.size());
    price[0] = unit_price;
    std::queue<int> queue;
    queue.push(0);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (auto &v : graph[u]) {
            price[v] = price[u] * (1 + rate);
            if (sink_nodes.find(v) == sink_nodes.end()) {
                queue.push(v);
            } else {
                ans += price[v] * graph[v][0];
            }
        }
    }
    return ans;
}


int main() {

    std::ios::sync_with_stdio(false);

    int n_node;
    double unit_price, rate;
    std::cin >> n_node >> unit_price >> rate;
    Graph graph(n_node);
    std::unordered_set<int> sink_nodes;
    for (int i=0; i<n_node; ++i) {
        int count;
        std::cin >> count;
        if (count == 0) {
            sink_nodes.insert(i);
            ++count;
        }
        while (count--) {
            int v;
            std::cin >> v;
            graph[i].push_back(v);
        }
    }
    
    std::cout << std::fixed << std::setprecision(1)
              << total_sales(graph, sink_nodes, unit_price, rate) << '\n'
              << std::defaultfloat;

    return 0;
}
