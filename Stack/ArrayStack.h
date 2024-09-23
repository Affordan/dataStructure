#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "Stack.h"
#include "../LinearList/ArrayList.h"

template <typename T>
class ArrayStack : public __Stack__<T> {
public:
    ArrayStack();
    ~ArrayStack();

    void push(const T& value) override;
    void pop() override;
    T top() const override;
    bool empty() const override;
    size_t size() const override;
    void clear() override;
    std::string toString() const override;

private:
    ArrayList<T> data;
};

template <typename T>
ArrayStack<T>::ArrayStack() : data() {
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::push(const T& value) {
    data.push_back(value);
}

template <typename T>
void ArrayStack<T>::pop() {
    if (!empty()) {
        data.pop_back();
    }
}

template <typename T>
T ArrayStack<T>::top() const {
    if (!empty()) {
        return data[data.size() - 1];
    }
    throw std::out_of_range("Stack is empty");
}

template <typename T>
bool ArrayStack<T>::empty() const {
    return data.empty();
}

template <typename T>
size_t ArrayStack<T>::size() const {
    return data.size();
}

template <typename T>
void ArrayStack<T>::clear() {
    data.clear();
}

template <typename T>
std::string ArrayStack<T>::toString() const {
    std::string result = "[";
    for (size_t i = data.size(); i > 0; --i) {
        result += std::to_string(data[i - 1]);
        if (i > 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

#endif // ARRAYSTACK_H

