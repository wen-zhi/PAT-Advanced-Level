#include <iostream>


struct Node {
    Node(int key): key(key) {};
    int key;
    Node *left = nullptr;
    Node *right = nullptr;
    int height = 1;
};


class AVLTree {
public:
    void insert(int key) {root = _insert(root, key);};
    Node *root = nullptr;
private:
    Node* _insert(Node *node, int key) {
        if (!node) return new Node(key);
        // insert
        if (key > node->key) {
            node->right = _insert(node->right, key);
        } else if (key < node->key) {
            node->left = _insert(node->left, key);
        }
        node->height = 1 + _max(_height(node->left), _height(node->right));
        // balance
        int balance_factor = _height(node->left) - _height(node->right);
        if (balance_factor > 1) {
            if (key > node->left->key) {
                node->left = _left_rotate(node->left);
            }
            node = _right_rotate(node);
        } else if (balance_factor < -1) {
            if (key < node->right->key) {
                node->right = _right_rotate(node->right);
            }
            node = _left_rotate(node);
        }
        return node;
    }

    Node* _left_rotate(Node *node) {
        Node *head = node->right;
        node->right = head->left;
        head->left = node;
        node->height = 1 + _max(_height(node->left), _height(node->right));
        head->height = 1 + _max(_height(head->left), _height(head->right));
        return head;
    }

    Node* _right_rotate(Node *node) {
        Node *head = node->left;
        node->left = head->right;
        head->right = node;
        node->height = 1 + _max(_height(node->left), _height(node->right));
        head->height = 1 + _max(_height(head->left), _height(head->right));
        return head;
    }

    int _height(Node *node) {
        if (node) return node->height;
        return 0;
    }

    int _max(int a, int b) {return a > b ? a : b;}
};


int main() {

    int n_node;
    std::cin >> n_node;
    AVLTree T;
    while (n_node--) {
        int key;
        std::cin >> key;
        T.insert(key);
    }

    std::cout << T.root->key << '\n';

    return 0;
}
