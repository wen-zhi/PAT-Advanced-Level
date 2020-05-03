#include <iostream>


typedef struct Node {
    // constructor
    Node(int key): key(key) {};
    // member
    int key;
    Node *left = nullptr;
    Node *right = nullptr;
    int height = 1;
} *AVLTree;


int max(int a, int b) {
    return a > b ? a : b;
}


int height(AVLTree &T) {
    if (T) return T->height;
    return 0;
}


void right_rotate(AVLTree &T) {
    AVLTree head = T->left;
    T->left = head->right;
    head->right = T;
    T->height = 1 + max(height(T->left), height(T->right));
    head->height = 1 + max(height(head->left), height(head->right));
    T = head;
}


void left_rotate(AVLTree &T) {
    AVLTree head = T->right;
    T->right = head->left;
    head->left = T;
    T->height = 1 + max(height(T->left), height(T->right));
    head->height = 1 + max(height(head->left), height(head->right));
    T = head;
}


void insert(AVLTree &T, int key) {
    if (!T) {
        T = new Node(key);
        return;
    }
    // insert
    if (key < T->key) {
        insert(T->left, key);
    } else if (key > T->key) {
        insert(T->right, key);
    }
    T->height = 1 + max(height(T->left), height(T->right));
    // balance
    int balance_factor = height(T->left) - height(T->right);
    if (balance_factor > 1) {
        if (T->left->key < key) {
            left_rotate(T->left);
        }
        right_rotate(T);
    } else if (balance_factor < -1) {
        if (T->right->key > key) {
            right_rotate(T->right);
        }
        left_rotate(T);
    }
}


int main() {

    int n_node;
    std::cin >> n_node;
    AVLTree T = nullptr;
    while (n_node--) {
        int key;
        std::cin >> key;
        insert(T, key);
    }

    std::cout << T->key << '\n';

    return 0;
}
