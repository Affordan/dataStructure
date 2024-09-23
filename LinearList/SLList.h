#ifndef SLLIST_H
#define SLLIST_H

#include "LinearList.h"
template <typename T>
class SLList : public __LinearList__<T> {
public:
    SLList();
    ~SLList();

    void push_back(const T& value) override;
    void pop_back() override;
    void push_front(const T& value) override;
    void pop_front() override;
    void insert(const T& value, size_t position) override;
    bool remove(size_t position) override;
    size_t find(const T& value) const override;
    size_t size() const override;
    bool empty() const override;
    void clear() override;
    void sort() override;
    void reverse() override;
    string toString() const override;

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head;
    size_t size_;

public:
    class Iterator {
    private:
        Node* current;
    public:
        Iterator(Node* node) : current(node) {}
        T& operator*() { return current->data; }
        Iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};

template <typename T>
SLList<T>::SLList() : head(nullptr), size_(0) {}

template <typename T>
SLList<T>::~SLList() {
    clear();
}

template <typename T>
void SLList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    ++size_;
}

template <typename T>
void SLList<T>::pop_back() {
    if (empty()) return;
    if (size_ == 1) {
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    --size_;
}

template <typename T>
void SLList<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    ++size_;
}

template <typename T>
void SLList<T>::pop_front() {
    if (empty()) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    --size_;
}

template <typename T>
void SLList<T>::insert(const T& value, size_t position) {
    if (position > size_) return;
    if (position == 0) {
        push_front(value);
    } else {
        Node* newNode = new Node(value);
        Node* current = head;
        for (size_t i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        ++size_;
    }
}

template <typename T>
bool SLList<T>::remove(size_t position) {
    if (position >= size_) return false;
    if (position == 0) {
        pop_front();
    } else {
        Node* current = head;
        for (size_t i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        --size_;
    }
    return true;
}

template <typename T>
size_t SLList<T>::find(const T& value) const {
    Node* current = head;
    size_t position = 0;
    while (current) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        ++position;
    }
    return size_;
}

template <typename T>
size_t SLList<T>::size() const {
    return size_;
}

template <typename T>
bool SLList<T>::empty() const {
    return size_ == 0;
}

template <typename T>
void SLList<T>::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    size_ = 0;
}

template <typename T>
void SLList<T>::sort() {
    if (size_ <= 1) return;
    SLList<T> sorted;
    while (head) {
        Node* current = head;
        head = head->next;
        current->next = nullptr;
        
        if (sorted.empty() || current->data <= sorted.head->data) {
            current->next = sorted.head;
            sorted.head = current;
        } else {
            Node* sortedCurrent = sorted.head;
            while (sortedCurrent->next && sortedCurrent->next->data < current->data) {
                sortedCurrent = sortedCurrent->next;
            }
            current->next = sortedCurrent->next;
            sortedCurrent->next = current;
        }
    }
    head = sorted.head;
    sorted.head = nullptr;
}

template <typename T>
void SLList<T>::reverse() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template <typename T>
string SLList<T>::toString() const {
    std::ostringstream oss;
    oss << "[";
    Node* current = head;
    while (current) {
        oss << current->data;
        if (current->next) {
            oss << ", ";
        }
        current = current->next;
    }
    oss << "]";
    return oss.str();
}
#endif  SLLIST_H