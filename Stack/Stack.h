#ifndef STACK_H
#define STACK_H

#include<iostream>

template<class T>
class __Stack__
{
public:
    virtual void push(const T& value) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual void clear() = 0;
    virtual std::string toString() const = 0;
};

#endif