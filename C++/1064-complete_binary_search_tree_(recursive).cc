#include <iostream>
#include <vector>
#include <algorithm>


void get_inorder_idx(int node_idx, int &n_node, std::vector<int> &res) {
    if (node_idx >= n_node) return;

    get_inorder_idx(node_idx * 2 + 1, n_node, res);
    res.push_back(node_idx);
    get_inorder_idx(node_idx * 2 + 2, n_node, res);
} 


int main() {

    int n_node;
    std::cin >> n_node;
    std::vector<int> inorder;
    for (int i=0; i<n_node; ++i) {
        int node;
        std::cin >> node;
        inorder.push_back(node);
    }
    std::sort(inorder.begin(), inorder.end());

    std::vector<int> inorder_idx;
    get_inorder_idx(0, n_node, inorder_idx);
    std::vector<int> tree(n_node);
    for (std::size_t i=0; i!=inorder.size(); ++i) {
        tree[inorder_idx[i]] = inorder[i];
    }

    auto iter = tree.begin();
    std::cout << *iter;
    for (++iter; iter!=tree.end(); ++iter) {
        std::cout << ' ' << *iter;
    }
    std::cout << '\n';

    return 0;
}
