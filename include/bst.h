// Copyright 2021 NNTU-CS
#ifndef BST_H
#define BST_H

#include <string>
#include <algorithm>
#include <vector>
#include <utility>

template<typename T>
class BST {
private:
    struct Node {
        T key;
        int count;
        Node* left;
        Node* right;
        Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void insert(Node*& node, const T& key) {
        if (!node) {
            node = new Node(key);
        } else if (key < node->key) {
            insert(node->left, key);
        } else if (key > node->key) {
            insert(node->right, key);
        } else {
            node->count++;
        }
    }

    int search(Node* node, const T& key) const {
        if (!node) return 0;
        if (key < node->key) return search(node->left, key);
        if (key > node->key) return search(node->right, key);
        return node->count;
    }

    int depth(Node* node) const {
        if (!node) return 0;
        return 1 + std::max(depth(node->left), depth(node->right));
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    void inorderCollect(Node* node, std::vector<std::pair<T, int>>& vec) const {
        if (node) {
            inorderCollect(node->left, vec);
            vec.emplace_back(node->key, node->count);
            inorderCollect(node->right, vec);
        }
    }

public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    void add(const T& key) {
        insert(root, key);
    }

    int search(const T& key) const {
        return search(root, key);
    }

    int depth() const {
        return depth(root);
    }

    std::vector<std::pair<T, int>> getAllNodes() const {
        std::vector<std::pair<T, int>> vec;
        inorderCollect(root, vec);
        return vec;
    }
};

#endif  // INCLUDE_BST_H_
