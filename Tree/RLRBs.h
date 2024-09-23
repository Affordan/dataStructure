#ifndef RLRBS_H
#define RLRBS_H

#include <iostream>
#include <string>

template <typename T>
class RLRB {
public:
    RLRB();
    ~RLRB();

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
    Node* moveRedLeft(Node* node);
    Node* moveRedRight(Node* node);
    Node* balance(Node* node);
    Node* min(Node* node) const;
    Node* deleteMin(Node* node);
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
RLRB<T>::RLRB() : root(nullptr), treeSize(0) {}

template <typename T>
RLRB<T>::~RLRB() {
    clear();
}

template <typename T>
void RLRB<T>::insert(const T& value) {
    root = insert(root, value);
    root->color = BLACK;
}

template <typename T>
typename RLRB<T>::Node* RLRB<T>::insert(Node* node, const T& value) {
    if (node == nullptr) {
        treeSize++;
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
bool RLRB<T>::search(const T& value) const {
    return search(root, value) != nullptr;
}

template <typename T>
typename RLRB<T>::Node* RLRB<T>::search(Node* node, const T& value) const {
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
void RLRB<T>::remove(const T& value) {
    if (search(value)) {
        root = remove(root, value);
        if (root != nullptr) {
            root->color = BLACK;
        }
    }
}

template <typename T>
typename RLRB<T>::Node* RLRB<T>::remove(Node* node, const T& value) {
    if (value < node->data) {
        if (!isRed(node->left) && !isRed(node->left->left)) {
            node = moveRedLeft(node);
        }
        node->left = remove(node->left, value);
    } else {
        if (isRed(node->left)) {
            node = rotateRight(node);
        }
        if (value == node->data && node->right == nullptr) {
            delete node;
            treeSize--;
            return nullptr;
        }
        if (!isRed(node->right) && !isRed(node->right->left)) {
            node = moveRedRight(node);
        }
        if (value == node->data) {
            Node* minNode = min(node->right);
            node->data = minNode->data;
            node->right = deleteMin(node->right);
        } else {
            node->right = remove(node->right, value);
        }
    }
    return balance(node);
}

template <typename T>
typename RLRB<T>::Node* RLRB<T>::moveRedLeft(Node* node) {
    flipColors(node);
    if (isRed(node->right->left)) {
        node->right = rotateRight(node->right);
        node = rotateLeft(node);
        flipColors(node);
    }
    return node;
}

template <typename T>
typename RLRB<T>::Node* RLRB<T>::moveRedRight(Node* node) {
    flipColors(node);
    if (isRed(node->left->left)) {
        node = rotateRight(node);
        flipColors(node);
    }
    return node;
}

template <typename T>
typename RLRB<T>::Node* RLRB<T>::balance(Node* node) {
    if (isRed(node->right)) {
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
typename RLRB<T>::Node* RLRB<T>::min(Node* node) const {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename T>
typename RLRB<T>::Node* RLRB<T>::deleteMin(Node* node) {
    if (node->left == nullptr) {
        delete node;
        treeSize--;
        return nullptr;
    }
    if (!isRed(node->left) && !isRed(node->left->left)) {
        node = moveRedLeft(node);
    }
    node->left = deleteMin(node->left);
    return balance(node);
}

template <typename T>
void RLRB<T>::clear() {
    clear(root);
    root = nullptr;
    treeSize = 0;
}

template <typename T>
void RLRB<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
bool RLRB<T>::empty() const {
    return root == nullptr;
}

template <typename T>
size_t RLRB<T>::size() const {
    return treeSize;
}

template <typename T>
std::string RLRB<T>::inOrderTraversal() const {
    std::string result;
    inOrderTraversal(root, result);
    return result;
}

template <typename T>
void RLRB<T>::inOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        inOrderTraversal(node->left, result);
        result += std::to_string(node->data) + " ";
        inOrderTraversal(node->right, result);
    }
}

template <typename T>
std::string RLRB<T>::preOrderTraversal() const {
    std::string result;
    preOrderTraversal(root, result);
    return result;
}

template <typename T>
void RLRB<T>::preOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        result += std::to_string(node->data) + " ";
        preOrderTraversal(node->left, result);
        preOrderTraversal(node->right, result);
    }
}

template <typename T>
std::string RLRB<T>::postOrderTraversal() const {
    std::string result;
    postOrderTraversal(root, result);
    return result;
}

template <typename T>
void RLRB<T>::postOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        postOrderTraversal(node->left, result);
        postOrderTraversal(node->right, result);
        result += std::to_string(node->data) + " ";
    }
}

template <typename T>
std::string RLRB<T>::toString() const {
    return inOrderTraversal();
}

template <typename T>
typename RLRB<T>::Node* RLRB<T>::rotateLeft(Node* node) {
    Node* x = node->right;
    node->right = x->left;
    x->left = node;
    x->color = node->color;
    node->color = RED;
    return x;
}

template <typename T>
typename RLRB<T>::Node* RLRB<T>::rotateRight(Node* node) {
    Node* x = node->left;
    node->left = x->right;
    x->right = node;
    x->color = node->color;
    node->color = RED;
    return x;
}

template <typename T>
void RLRB<T>::flipColors(Node* node) {
    node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
}

template <typename T>
bool RLRB<T>::isRed(Node* node) const {
    if (node == nullptr) {
        return false;
    }
    return node->color == RED;
}

#endif // RLRBS_H

