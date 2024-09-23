#ifndef LLRBS_H
#define LLRBS_H

#include <iostream>
#include <string>

template <typename T>
class LLRB {
public:
    LLRB();
    ~LLRB();

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
    enum Color { RED, BLACK };

    struct Node {
        T data;
        Node* left;
        Node* right;
        Color color;

        Node(const T& value, Color color) : data(value), left(nullptr), right(nullptr), color(color) {}
    };

    Node* root;
    size_t treeSize;

    Node* insert(Node* node, const T& value);
    Node* search(Node* node, const T& value) const;
    Node* remove(Node* node, const T& value);
    void clear(Node* node);
    void inOrderTraversal(Node* node, std::string& result) const;
    void preOrderTraversal(Node* node, std::string& result) const;
    void postOrderTraversal(Node* node, std::string& result) const;

    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    void flipColors(Node* node);
    bool isRed(Node* node) const;
};

template <typename T>
LLRB<T>::LLRB() : root(nullptr), treeSize(0) {}

template <typename T>
LLRB<T>::~LLRB() {
    clear();
}

template <typename T>
void LLRB<T>::insert(const T& value) {
    root = insert(root, value);
    root->color = BLACK;
    ++treeSize;
}

template <typename T>
typename LLRB<T>::Node* LLRB<T>::insert(Node* node, const T& value) {
    if (node == nullptr) {
        return new Node(value, RED);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    }

    if (isRed(node->right) && !isRed(node->left)) {
        node = rotateLeft(node);
    }
    if (isRed(node->left) && isRed(node->left->left)) {
        node = rotateRight(node);
    }
    if (isRed(node->left) && isRed(node->right)) {
        flipColors(node);
    }

    return node;
}

template <typename T>
bool LLRB<T>::search(const T& value) const {
    return search(root, value) != nullptr;
}

template <typename T>
typename LLRB<T>::Node* LLRB<T>::search(Node* node, const T& value) const {
    if (node == nullptr) {
        return nullptr;
    }

    if (value < node->data) {
        return search(node->left, value);
    } else if (value > node->data) {
        return search(node->right, value);
    } else {
        return node;
    }
}

template <typename T>
void LLRB<T>::remove(const T& value) {
    // Implementation of remove function is complex and is omitted for brevity
}

template <typename T>
void LLRB<T>::clear() {
    clear(root);
    root = nullptr;
    treeSize = 0;
}

template <typename T>
void LLRB<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
bool LLRB<T>::empty() const {
    return root == nullptr;
}

template <typename T>
size_t LLRB<T>::size() const {
    return treeSize;
}

template <typename T>
std::string LLRB<T>::inOrderTraversal() const {
    std::string result;
    inOrderTraversal(root, result);
    return result;
}

template <typename T>
void LLRB<T>::inOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        inOrderTraversal(node->left, result);
        result += std::to_string(node->data) + " ";
        inOrderTraversal(node->right, result);
    }
}

template <typename T>
std::string LLRB<T>::preOrderTraversal() const {
    std::string result;
    preOrderTraversal(root, result);
    return result;
}

template <typename T>
void LLRB<T>::preOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        result += std::to_string(node->data) + " ";
        preOrderTraversal(node->left, result);
        preOrderTraversal(node->right, result);
    }
}

template <typename T>
std::string LLRB<T>::postOrderTraversal() const {
    std::string result;
    postOrderTraversal(root, result);
    return result;
}

template <typename T>
void LLRB<T>::postOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        postOrderTraversal(node->left, result);
        postOrderTraversal(node->right, result);
        result += std::to_string(node->data) + " ";
    }
}

template <typename T>
std::string LLRB<T>::toString() const {
    return inOrderTraversal();
}

template <typename T>
typename LLRB<T>::Node* LLRB<T>::rotateLeft(Node* node) {
    Node* x = node->right;
    node->right = x->left;
    x->left = node;
    x->color = node->color;
    node->color = RED;
    return x;
}

template <typename T>
typename LLRB<T>::Node* LLRB<T>::rotateRight(Node* node) {
    Node* x = node->left;
    node->left = x->right;
    x->right = node;
    x->color = node->color;
    node->color = RED;
    return x;
}

template <typename T>
void LLRB<T>::flipColors(Node* node) {
    node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
}

template <typename T>
bool LLRB<T>::isRed(Node* node) const {
    if (node == nullptr) {
        return false;
    }
    return node->color == RED;
}

#endif // LLRBS_H

