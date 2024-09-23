#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "LinearList.h"
#include <algorithm>
template <typename T> class ArrayList : public __LinearList__<T> {

  public:
    ArrayList();
    ~ArrayList();

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
    string toString() const override;
    T &operator[](size_t index) override;
    const T &operator[](size_t index) const override;

    class Iterator {
      private:
        T *ptr;

      public:
        Iterator(T *p);
        T &operator*();
        Iterator &operator++();
        bool operator!=(const Iterator &other) const;
    };

    Iterator begin();
    Iterator end();

  private:
    T *data;
    size_t capacity;
    size_t size_;

    void resize(size_t newCapacity);
};

template <typename T> ArrayList<T>::ArrayList() : data(nullptr), capacity(0), size_(0) {
    resize(10); // Initial capacity
}

template <typename T> ArrayList<T>::~ArrayList() {
    delete[] data;
}

template <typename T> void ArrayList<T>::push_back(const T &value) {
    if (size_ == capacity) {
        resize(capacity * 2);
    }
    data[size_++] = value;
}

template <typename T> void ArrayList<T>::pop_back() {
    if (!empty()) {
        --size_;
    }
}

template <typename T> void ArrayList<T>::push_front(const T &value) {
    insert(value, 0);
}

template <typename T> void ArrayList<T>::pop_front() {
    remove(0);
}

template <typename T> void ArrayList<T>::insert(const T &value, size_t position) {
    if (position > size_) {
        return;
    }
    if (size_ == capacity) {
        resize(capacity * 2);
    }
    for (size_t i = size_; i > position; --i) {
        data[i] = data[i - 1];
    }
    data[position] = value;
    ++size_;
}

template <typename T> bool ArrayList<T>::remove(size_t position) {
    if (position >= size_) {
        return false;
    }
    for (size_t i = position; i < size_ - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size_;
    return true;
}

template <typename T> size_t ArrayList<T>::find(const T &value) const {
    for (size_t i = 0; i < size_; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return size_; // Not found
}

template <typename T> size_t ArrayList<T>::size() const {
    return size_;
}

template <typename T> bool ArrayList<T>::empty() const {
    return size_ == 0;
}

template <typename T> void ArrayList<T>::clear() {
    size_ = 0;
}

template <typename T> void ArrayList<T>::sort() {
    std::sort(data, data + size_);
}

template <typename T> void ArrayList<T>::reverse() {
    std::reverse(data, data + size_);
}

template <typename T> string ArrayList<T>::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < size_; ++i) {
        oss << data[i];
        if (i < size_ - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

template <typename T> typename ArrayList<T>::Iterator ArrayList<T>::begin() {
    return Iterator(data);
}

template <typename T> typename ArrayList<T>::Iterator ArrayList<T>::end() {
    return Iterator(data + size_);
}

template <typename T> void ArrayList<T>::resize(size_t newCapacity) {
    T *newData = new T[newCapacity];
    for (size_t i = 0; i < size_; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T> ArrayList<T>::Iterator::Iterator(T *p) : ptr(p) {
}

template <typename T> T &ArrayList<T>::Iterator::operator*() {
    return *ptr;
}

template <typename T> typename ArrayList<T>::Iterator &ArrayList<T>::Iterator::operator++() {
    ++ptr;
    return *this;
}

template <typename T> bool ArrayList<T>::Iterator::operator!=(const Iterator &other) const {
    return ptr != other.ptr;
}

template <typename T> T &ArrayList<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T> const T &ArrayList<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}



#endif // !ARRAYLIST_h
