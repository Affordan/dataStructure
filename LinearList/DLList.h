#ifndef DLLIST_H
#define DLLIST_H

#include "LinearList.h"

template <typename T> class DLList : public __LinearList__<T> {
  public:
    DLList();
    ~DLList();

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
    T& operator[](size_t index) override;
    const T& operator[](size_t index) const override;

  private:
    struct Node {
        T data;
        Node *prev;
        Node *next;
        Node(const T &value) : data(value), prev(nullptr), next(nullptr) {
        }
    };

    Node *head;
    Node *tail;
    size_t size_;
};

template <typename T> DLList<T>::DLList() : head(nullptr), tail(nullptr), size_(0) {
}

template <typename T> DLList<T>::~DLList() {
    clear();
}

template <typename T> void DLList<T>::push_back(const T &value) {
    Node *newNode = new Node(value);
    if (empty()) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size_++;
}

template <typename T> void DLList<T>::pop_back() {
    if (empty())
        return;
    Node *temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size_--;
}

template <typename T> void DLList<T>::push_front(const T &value) {
    Node *newNode = new Node(value);
    if (empty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size_++;
}

template <typename T> void DLList<T>::pop_front() {
    if (empty())
        return;
    Node *temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size_--;
}

template <typename T> void DLList<T>::insert(const T &value, size_t position) {
    if (position > size_)
        return;
    if (position == 0) {
        push_front(value);
    } else if (position == size_) {
        push_back(value);
    } else {
        Node *newNode = new Node(value);
        Node *current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        newNode->prev = current->prev;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        size_++;
    }
}

template <typename T> bool DLList<T>::remove(size_t position) {
    if (position >= size_)
        return false;
    if (position == 0) {
        pop_front();
    } else if (position == size_ - 1) {
        pop_back();
    } else {
        Node *current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size_--;
    }
    return true;
}

template <typename T> size_t DLList<T>::find(const T &value) const {
    Node *current = head;
    size_t position = 0;
    while (current) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    return size_;
}

template <typename T> size_t DLList<T>::size() const {
    return size_;
}

template <typename T> bool DLList<T>::empty() const {
    return size_ == 0;
}

template <typename T> void DLList<T>::clear() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size_ = 0;
}

template <typename T> void DLList<T>::sort() {
    if (size_ <= 1)
        return;
    bool swapped;
    Node *current;
    Node *last = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

template <typename T> void DLList<T>::reverse() {
    Node *temp = nullptr;
    Node *current = head;

    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp) {
        head = temp->prev;
    }

    std::swap(head, tail);
}

template <typename T> std::string DLList<T>::toString() const {
    std::ostringstream oss;
    oss << "[";
    Node *current = head;
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

template <typename T>
T& DLList<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
const T& DLList<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (size_t i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

#endif // DLLIST_H