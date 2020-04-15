#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>


// types
using Graph = std::map<std::string, std::set<std::string>>;
using Head = std::pair<std::string, int>;  // (head, n_member)
struct Gang {
    std::string head;
    int n_member, total_weight;
};


Graph graph;
std::map<std::string, int> head_weights;
std::map<std::string, int> edge_weights;
std::map<std::string, bool> visited;


Gang bfs(std::string u) {
    int max_h_height = 0;
    int n_member = 0, total_weight = 0;
    std::string head;
    std::queue<std::string> Queue;
    Queue.push(u);
    visited[u] = true;
    while (!Queue.empty()) {
        std::string u = Queue.front();
        Queue.pop();
        ++n_member;
        if (head_weights[u] > max_h_height) {
            head = u;
            max_h_height = head_weights[u];
        }
        for (auto &v : graph[u]) {
            total_weight += edge_weights[u + v];
            if (!visited[v]) {
                Queue.push(v);
                visited[v] = true;
            }
        }
    }
    return {head, n_member, total_weight};
}


std::vector<Head> head_of_gang(int thre) {
    std::vector<Head> heads;
    for (auto &kv : graph) {
        if (!visited[kv.first]) {
            Gang gang = bfs(kv.first);
            if (gang.n_member > 2 && gang.total_weight > thre) {
                heads.push_back(std::make_pair(gang.head, gang.n_member));
            }
        }
    }
    std::sort(heads.begin(), heads.end());
    return heads;
}


int main() {

    int n_call, thre;
    std::cin >> n_call >> thre;

    std::string u, v;
    int w;
    while (n_call--) {
        std::cin >> u >> v >> w;
        graph[u].insert(v);
        graph[v].insert(u);
        head_weights[u] += w;
        head_weights[v] += w;
        edge_weights[u + v] = w;
    }

    std::vector<Head> heads = head_of_gang(thre);
    std::cout << heads.size() << '\n';
    for (auto &x : heads) {
        std::cout << x.first << ' ' << x.second << '\n';
    }
    
    return 0;
}
