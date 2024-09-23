#ifndef BTREES_H
#define BTREES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

template <typename T>
class BTree {
public:
    BTree(int t);
    ~BTree();

    void insert(const T& value);
    bool search(const T& value) const;
    void remove(const T& value);
    void clear();
    bool empty() const;
    size_t size() const;
    std::string inOrderTraversal() const;
    std::string preOrderTraversal() const;
    std::string postOrderTraversal() const;
    std::string toString() const;

private:
    struct Node {
        std::list<T> keys;
        std::list<Node*> children;
        bool leaf;

        Node(bool leaf);
    };

    Node* root;
    int t; // Minimum degree
    size_t treeSize;

    void insertNonFull(Node* node, const T& value);
    void splitChild(Node* node, typename std::list<Node*>::iterator it, Node* y);
    bool search(Node* node, const T& value) const;
    void remove(Node* node, const T& value);
    void clear(Node* node);
    void inOrderTraversal(Node* node, std::string& result) const;
    void preOrderTraversal(Node* node, std::string& result) const;
    void postOrderTraversal(Node* node, std::string& result) const;
};

template <typename T>
BTree<T>::BTree(int t) : root(nullptr), t(t), treeSize(0) {}

template <typename T>
BTree<T>::~BTree() {
    clear();
}

template <typename T>
void BTree<T>::insert(const T& value) {
    if (root == nullptr) {
        root = new Node(true);
        root->keys.push_back(value);
    } else {
        if (root->keys.size() == 2 * t - 1) {
            Node* s = new Node(false);
            s->children.push_back(root);
            splitChild(s, s->children.begin(), root);
            root = s;
        }
        insertNonFull(root, value);
    }
    ++treeSize;
}

template <typename T>
void BTree<T>::insertNonFull(Node* node, const T& value) {
    if (node->leaf) {
        node->keys.push_back(value);
        node->keys.sort();
    } else {
        auto it = node->keys.begin();
        auto childIt = node->children.begin();
        while (it != node->keys.end() && value > *it) {
            ++it;
            ++childIt;
        }
        if ((*childIt)->keys.size() == 2 * t - 1) {
            splitChild(node, childIt, *childIt);
            if (value > *it) {
                ++it;
                ++childIt;
            }
        }
        insertNonFull(*childIt, value);
    }
}

template <typename T>
void BTree<T>::splitChild(Node* node, typename std::list<Node*>::iterator it, Node* y) {
    Node* z = new Node(y->leaf);
    auto keyIt = y->keys.begin();
    std::advance(keyIt, t);
    z->keys.splice(z->keys.begin(), y->keys, keyIt, y->keys.end());

    if (!y->leaf) {
        auto childIt = y->children.begin();
        std::advance(childIt, t);
        z->children.splice(z->children.begin(), y->children, childIt, y->children.end());
    }

    node->children.insert(std::next(it), z);
    node->keys.insert(it, y->keys.back());
    y->keys.pop_back();
}

template <typename T>
bool BTree<T>::search(const T& value) const {
    return search(root, value);
}

template <typename T>
bool BTree<T>::search(Node* node, const T& value) const {
    if (node == nullptr) {
        return false;
    }

    auto it = node->keys.begin();
    while (it != node->keys.end() && value > *it) {
        ++it;
    }

    if (it != node->keys.end() && value == *it) {
        return true;
    }

    if (node->leaf) {
        return false;
    }

    auto childIt = node->children.begin();
    std::advance(childIt, std::distance(node->keys.begin(), it));
    return search(*childIt, value);
}

template <typename T>
void BTree<T>::remove(const T& value) {
    // Implementation of remove function is complex and is omitted for brevity
}

template <typename T>
void BTree<T>::clear() {
    clear(root);
    root = nullptr;
    treeSize = 0;
}

template <typename T>
void BTree<T>::clear(Node* node) {
    if (node != nullptr) {
        for (auto child : node->children) {
            clear(child);
        }
        delete node;
    }
}

template <typename T>
bool BTree<T>::empty() const {
    return root == nullptr;
}

template <typename T>
size_t BTree<T>::size() const {
    return treeSize;
}

template <typename T>
std::string BTree<T>::inOrderTraversal() const {
    std::string result;
    inOrderTraversal(root, result);
    return result;
}

template <typename T>
void BTree<T>::inOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        auto it = node->keys.begin();
        auto childIt = node->children.begin();
        while (it != node->keys.end()) {
            if (!node->leaf) {
                inOrderTraversal(*childIt, result);
                ++childIt;
            }
            result += std::to_string(*it) + " ";
            ++it;
        }
        if (!node->leaf) {
            inOrderTraversal(*childIt, result);
        }
    }
}

template <typename T>
std::string BTree<T>::preOrderTraversal() const {
    std::string result;
    preOrderTraversal(root, result);
    return result;
}

template <typename T>
void BTree<T>::preOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        for (const auto& key : node->keys) {
            result += std::to_string(key) + " ";
        }
        for (auto child : node->children) {
            preOrderTraversal(child, result);
        }
    }
}

template <typename T>
std::string BTree<T>::postOrderTraversal() const {
    std::string result;
    postOrderTraversal(root, result);
    return result;
}

template <typename T>
void BTree<T>::postOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        for (auto child : node->children) {
            postOrderTraversal(child, result);
        }
        for (const auto& key : node->keys) {
            result += std::to_string(key) + " ";
        }
    }
}

template <typename T>
std::string BTree<T>::toString() const {
    return inOrderTraversal();
}

template <typename T>
BTree<T>::Node::Node(bool leaf) : leaf(leaf) {}

#endif // BTREES_H

