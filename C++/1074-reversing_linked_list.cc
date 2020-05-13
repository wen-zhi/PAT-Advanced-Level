#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


struct Node {
    std::string addr, data, next;
};


std::vector<Node>
reversing_linked_list(const std::vector<Node> &linked_list, int k)
{
    int n_node = linked_list.size();
    std::vector<Node> r_linked_list;
    int count = 0;
    for (int i=0; i<n_node; i+=k) {
        if (i + k <= n_node) {
            for (int r_i=i+k-1; r_i>=i; --r_i) {
                Node node = linked_list[r_i];
                if (count > 0) {
                    r_linked_list[count-1].next = node.addr;
                }
                r_linked_list.push_back(node);
                ++count;
            }
        } else {
            if (count > 0) {
                r_linked_list[count-1].next = linked_list[i].addr;
            }
            for (int r_i=i; r_i<n_node; ++r_i) {
                r_linked_list.push_back(linked_list[r_i]);
            }
        }
    }
    r_linked_list[n_node-1].next = "-1";
    return r_linked_list;
}


int main() {

    std::ios::sync_with_stdio(false);

    std::string head;
    int n_node, k;
    std::cin >> head >> n_node >> k;

    std::unordered_map<std::string, Node> nodes;
    while (n_node--) {
        std::string addr, data, next;
        std::cin >> addr >> data >> next;
        nodes[addr] = {addr, data, next};
    }

    std::vector<Node> linked_list;
    std::string next = head;
    while (next != "-1") {
        Node node = nodes[next];
        linked_list.push_back(node);
        next = node.next;
    }

    auto r_linked_list = reversing_linked_list(linked_list, k);
    for (Node &node : r_linked_list) {
        std::cout << node.addr << ' ' << node.data << ' ' << node.next << '\n';
    }

    return 0;
}
