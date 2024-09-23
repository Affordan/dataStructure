#ifndef CLLIST_H
#define CLLIST_H

#include "LinearList.h"

template <typename T> class CLList : public __LinearList__<T> {
  public:
    CLList();
    ~CLList();

    void push_back(const T &value) override;
    void pop_back() override;
    void push_front(const T &value) override;
    void pop_front() override;
    void insert(const T &value, size_t position) override;
    bool remove(size_t position) override;
    size_t find(const T &value) const override;
    size_t size() const override;
    bool empty() const override;
    void clear() override;
    void sort() override;
    void reverse() override;
    std::string toString() const override;
    T &operator[](size_t index) override;
    const T &operator[](size_t index) const override;

  private:
    struct Node {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {
        }
    };

    Node *tail;
    size_t size_;
};

template <typename T> CLList<T>::CLList() : tail(nullptr), size_(0) {
}

template <typename T> CLList<T>::~CLList() {
    clear();
}

template <typename T> void CLList<T>::push_back(const T &value) {
    Node *newNode = new Node(value);
    if (empty()) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    size_++;
}

template <typename T> void CLList<T>::pop_back() {
    if (empty())
        return;
    if (size_ == 1) {
        delete tail;
        tail = nullptr;
    } else {
        Node *current = tail->next;
        while (current->next != tail) {
            current = current->next;
        }
        current->next = tail->next;
        delete tail;
        tail = current;
    }
    size_--;
}

template <typename T> void CLList<T>::push_front(const T &value) {
    Node *newNode = new Node(value);
    if (empty()) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    size_++;
}

template <typename T> void CLList<T>::pop_front() {
    if (empty())
        return;
    if (size_ == 1) {
        delete tail;
        tail = nullptr;
    } else {
        Node *front = tail->next;
        tail->next = front->next;
        delete front;
    }
    size_--;
}

template <typename T> void CLList<T>::insert(const T &value, size_t position) {
    if (position > size_)
        return;
    if (position == 0) {
        push_front(value);
    } else if (position == size_) {
        push_back(value);
    } else {
        Node *newNode = new Node(value);
        Node *current = tail->next;
        for (size_t i = 0; i < position - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size_++;
    }
}

template <typename T> bool CLList<T>::remove(size_t position) {
    if (position >= size_)
        return false;
    if (position == 0) {
        pop_front();
    } else {
        Node *current = tail->next;
        for (size_t i = 0; i < position - 1; i++) {
            current = current->next;
        }
        Node *toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete == tail) {
            tail = current;
        }
        delete toDelete;
        size_--;
    }
    return true;
}

template <typename T> size_t CLList<T>::find(const T &value) const {
    if (empty())
        return size_;
    Node *current = tail->next;
    for (size_t i = 0; i < size_; i++) {
        if (current->data == value)
            return i;
        current = current->next;
    }
    return size_;
}

template <typename T> size_t CLList<T>::size() const {
    return size_;
}

template <typename T> bool CLList<T>::empty() const {
    return size_ == 0;
}

template <typename T> void CLList<T>::clear() {
    if (empty())
        return;
    Node *current = tail->next;
    while (current != tail) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    delete tail;
    tail = nullptr;
    size_ = 0;
}

template <typename T> void CLList<T>::sort() {
    if (size_ <= 1)
        return;
    for (size_t i = 0; i < size_ - 1; i++) {
        Node *current = tail->next;
        for (size_t j = 0; j < size_ - i - 1; j++) {
            if (current->data > current->next->data) {
                T temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
    }
}

template <typename T> void CLList<T>::reverse() {
    if (size_ <= 1)
        return;
    Node *prev = tail;
    Node *current = tail->next;
    Node *next = nullptr;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != tail->next);
    tail = tail->next;
}

template <typename T> std::string CLList<T>::toString() const {
    if (empty())
        return "[]";
    std::string result = "[";
    Node *current = tail->next;
    do {
        result += std::to_string(current->data);
        current = current->next;            
        if (current != tail->next)
            result += ", ";
    } while (current != tail->next);
    result += "]";
    return result;
}

template <typename T> T &CLList<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    Node *current = tail->next;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T> const T &CLList<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    Node *current = tail->next;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

#endif
