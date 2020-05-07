#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <queue>
#include <utility>
#include <iomanip>


struct AdjNode {
    int node;
    double w;
};


using Graph = std::vector<std::vector<AdjNode>>;
const double inf = std::numeric_limits<double>::infinity();


std::vector<double> Dijkstra(Graph &graph, int src) {
    std::vector<double> dist(graph.size(), inf);
    dist[src] = 0;
    std::priority_queue<std::pair<int, int>> queue;
    queue.push(std::make_pair(dist[src], src));
    while (!queue.empty()) {
        int u = queue.top().second;
        queue.pop();
        for (auto &adj_node : graph[u]) {
            int v = adj_node.node;
            double alt_dist = dist[u] + adj_node.w;
            if (alt_dist < dist[v]) {
                dist[v] = alt_dist;
                queue.push(std::make_pair(dist[v], v));
            }
        }
    }
    return dist;
}


int main() {

    int n_house, n_gas_station, n_edge, max_range;
    std::cin >> n_house >> n_gas_station >> n_edge >> max_range;
    Graph graph(n_house + n_gas_station + 1);
    for (int i=0; i<n_edge; ++i) {
        int u, v;
        std::string temp;
        std::cin >> temp;
        if (temp[0] == 'G') {
            u = n_house + std::stoi(temp.substr(1));
        } else {
            u = std::stoi(temp);
        }
        std::cin >> temp;
        if (temp[0] == 'G') {
            v = n_house + std::stoi(temp.substr(1));
        } else {
            v = std::stoi(temp);
        }
        double w;
        std::cin >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // choose gas station
    double max_min_dist = -inf, min_avg_dist = inf;
    std::string best_gas_station;
    for (int i=1; i<=n_gas_station; ++i) {
        int gas_station = n_house + i;
        std::vector<double> dist = Dijkstra(graph, gas_station);
        double min_dist = inf, dist_sum = 0.;
        bool beyond_range = false;
        for (int house=1; house<=n_house; ++house) {
            double dist_to_house = dist[house];
            if (dist_to_house > max_range) {
                beyond_range = true;
                break;
            }
            if (dist_to_house < min_dist) {
                min_dist = dist_to_house;
            }
            dist_sum += dist_to_house;
        }
        if (beyond_range) {
            continue;
        } else {
            double avg_dist = dist_sum / n_house;
            if (min_dist > max_min_dist) {
                max_min_dist = min_dist;
                min_avg_dist = avg_dist;
                best_gas_station = std::string("G") + std::to_string(i);
            } else if (min_dist == max_min_dist) {
                if (avg_dist < min_avg_dist) {
                    min_avg_dist = avg_dist;
                    best_gas_station = std::string("G") + std::to_string(i);
                }
            }
        }
    }
    if (best_gas_station.empty()) {
        std::cout << "No Solution\n";
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << best_gas_station << '\n';
        std::cout << max_min_dist << ' ' << min_avg_dist << '\n';
        std::cout << std::defaultfloat;
    }  
    return 0;
}
