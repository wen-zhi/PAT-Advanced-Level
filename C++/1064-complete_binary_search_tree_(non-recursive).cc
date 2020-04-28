#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int> get_inorder_idx(int n_node) {
    std::vector<int> res;
    std::vector<int> stack;
    int node = 0;  // start from root
    while (true) {
        while (node < n_node) {
            stack.push_back(node);
            node = node * 2 + 1;  // lchild
        }
        bool to_rchild = false;
        while (!stack.empty()) {
            node = stack.back();
            res.push_back(node);
            stack.pop_back();
            int rchild = node * 2 + 2;
            if (rchild < n_node) {
                node = rchild;
                to_rchild = true;
                break;
            }
        }
        if (stack.empty() && !to_rchild) break;
    }
    return res;
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

    auto inorder_idx = get_inorder_idx(n_node);
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
