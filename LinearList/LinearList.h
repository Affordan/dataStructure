#ifndef LINEARLIST_H
#define LINEARLIST_H
#include <iostream>
#include<string>
#include<sstream>
using namespace std;

template <typename T>
class __LinearList__ {
public:
	__LinearList__() {};
	virtual ~__LinearList__() {};


public:
	virtual void push_back(const T& value) {};
	virtual void pop_back() {};
	virtual void push_front(const T& value) {};
	virtual void pop_front() {};
	virtual void insert(const T& value, size_t position) {};
	virtual bool remove(size_t position) =0;
	virtual size_t find(const T& value) const =0;
	virtual size_t size() const =0;
	virtual bool empty() const =0;
	virtual void clear() {};
	virtual void sort() {};
	virtual void reverse() {};
	virtual string toString() const = 0;
	virtual T& operator[](size_t index) = 0;
	virtual const T& operator[](size_t index) const = 0;
	
class Iterator;
	 Iterator begin() {};
	 Iterator end() {};
};


#endif // !LINEARLIST_H

