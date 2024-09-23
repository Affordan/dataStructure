#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "Stack.h"
#include <stdexcept>
#include <string>

template <typename T>
class LinkedStack : public __Stack__<T> {
public:
    LinkedStack();
    ~LinkedStack();

    void push(const T& value) override;
    void pop() override;
    T top() const override;
    bool empty() const override;
    size_t size() const override;
    void clear() override;
    std::string toString() const override;

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node* head;
    size_t stackSize;
};

template <typename T>
LinkedStack<T>::LinkedStack() : head(nullptr), stackSize(0) {
}

template <typename T>
LinkedStack<T>::~LinkedStack() {
    clear();
}

template <typename T>
void LinkedStack<T>::push(const T& value) {
    head = new Node(value, head);
    ++stackSize;
}

template <typename T>
void LinkedStack<T>::pop() {
    if (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        --stackSize;
    } else {
        throw std::out_of_range("Stack is empty");
    }
}

template <typename T>
T LinkedStack<T>::top() const {
    if (!empty()) {
        return head->data;
    }
    throw std::out_of_range("Stack is empty");
}

template <typename T>
bool LinkedStack<T>::empty() const {
    return head == nullptr;
}

template <typename T>
size_t LinkedStack<T>::size() const {
    return stackSize;
}

template <typename T>
void LinkedStack<T>::clear() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
std::string LinkedStack<T>::toString() const {
    std::string result = "[";
    Node* current = head;
    while (current != nullptr) {
        result += std::to_string(current->data);
        if (current->next != nullptr) {
            result += ", ";
        }
        current = current->next;
    }
    result += "]";
    return result;
}

#endif // LINKEDSTACK_H
