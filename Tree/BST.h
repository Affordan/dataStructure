#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

template <typename T>
class BST {
public:
    BST();
    ~BST();

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
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    size_t treeSize;

    void insert(Node*& node, const T& value);
    bool search(Node* node, const T& value) const;
    void remove(Node*& node, const T& value);
    void clear(Node* node);
    void inOrderTraversal(Node* node, std::string& result) const;
    void preOrderTraversal(Node* node, std::string& result) const;
    void postOrderTraversal(Node* node, std::string& result) const;
};

template <typename T>
BST<T>::BST() : root(nullptr), treeSize(0) {}

template <typename T>
BST<T>::~BST() {
    clear();
}

template <typename T>
void BST<T>::insert(const T& value) {
    insert(root, value);
}

template <typename T>
void BST<T>::insert(Node*& node, const T& value) {
    if (node == nullptr) {
        node = new Node(value);
        ++treeSize;
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
}

template <typename T>
bool BST<T>::search(const T& value) const {
    return search(root, value);
}

template <typename T>
bool BST<T>::search(Node* node, const T& value) const {
    if (node == nullptr) {
        return false;
    } else if (value == node->data) {
        return true;
    } else if (value < node->data) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

template <typename T>
void BST<T>::remove(const T& value) {
    remove(root, value);
}

template <typename T>
void BST<T>::remove(Node*& node, const T& value) {
    if (node == nullptr) {
        return;
    } else if (value < node->data) {
        remove(node->left, value);
    } else if (value > node->data) {
        remove(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
            --treeSize;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
            --treeSize;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
            --treeSize;
        } else {
            Node* temp = node->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            node->data = temp->data;
            remove(node->right, temp->data);
        }
    }
}

template <typename T>
void BST<T>::clear() {
    clear(root);
    root = nullptr;
    treeSize = 0;
}

template <typename T>
void BST<T>::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <typename T>
bool BST<T>::empty() const {
    return root == nullptr;
}

template <typename T>
size_t BST<T>::size() const {
    return treeSize;
}

template <typename T>
std::string BST<T>::inOrderTraversal() const {
    std::string result;
    inOrderTraversal(root, result);
    return result;
}

template <typename T>
void BST<T>::inOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        inOrderTraversal(node->left, result);
        result += std::to_string(node->data) + " ";
        inOrderTraversal(node->right, result);
    }
}

template <typename T>
std::string BST<T>::preOrderTraversal() const {
    std::string result;
    preOrderTraversal(root, result);
    return result;
}

template <typename T>
void BST<T>::preOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        result += std::to_string(node->data) + " ";
        preOrderTraversal(node->left, result);
        preOrderTraversal(node->right, result);
    }
}

template <typename T>
std::string BST<T>::postOrderTraversal() const {
    std::string result;
    postOrderTraversal(root, result);
    return result;
}

template <typename T>
void BST<T>::postOrderTraversal(Node* node, std::string& result) const {
    if (node != nullptr) {
        postOrderTraversal(node->left, result);
        postOrderTraversal(node->right, result);
        result += std::to_string(node->data) + " ";
    }
}

template <typename T>
std::string BST<T>::toString() const {
    return inOrderTraversal();
}

#endif // BST_H
