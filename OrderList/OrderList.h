#include <iostream>
#include <memory>
#include <cstdlib>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::string;
using std::stringstream;

template <class T>
class OrderList
{
private:
	T* items;
	int size_;
	int capacity;

public:
	OrderList();
	~OrderList();


private:
	void reseize();

public:
	void push_back(T x);
	void push_front(T x);
	T back();
	T front();
	bool empty();
	int size();
	T get(int i);		// get the ith item in OrderList
	void remove();		//default remove the last item
	void remove(int t);	
	string toString();


	friend ostream& operator<<(ostream& os, const OrderList<T>& ol);
	
};


template<class T>
OrderList<T>::OrderList()
{
	items = new T[100];
	size_ = 0;
	capacity = 0;
}

template<class T>
OrderList<T>::~OrderList()
{
	delete[] items;
}

template<class T>
inline void OrderList<T>::reseize()
{
	if (size_ == capacity)
	{
		// can be optimized ?
		capacity *= 2;
		T* nitem = new T[capacity];
		memcpy(nitem, this->items, size_);
		delete[]items;
		items = nitem;
		nitem = nullptr;

	}
}

template<class T>
void OrderList<T>::push_back(T x)
{
	items[size_] = x;
	size_++;
}

template<class T>
void OrderList<T>::push_front(T x)
{
	size_++;
	for (int i = size_; i > 0; i--)
	{
		items[i] = items[i - 1];
	}
	items[0] = x;
}

template<class T>
T OrderList<T>::back()
{
	return items[size_ - 1];
}

template<class T>
T OrderList<T>::front()
{
	return items[0];
}

template<class T>
bool OrderList<T>::empty()
{
	return size_ == 0;
}

template<class T>
int OrderList<T>::size()
{
	return size_;
}

template<class T>
inline T OrderList<T>::get(int i)
{
	return items[i-1];
}

template<class T>
inline void OrderList<T>::remove()
{
	items[size_ - 1] = 0;
	size_--;
}

template<class T>
inline void OrderList<T>::remove(int t)
{
	for (int i = t-1; i < size; i++)
	{
		//a[i] = a[i + 1];   a mistake.remember using the correct member in the class
		items[i] = items[i + 1];
	}
	size_--;
}

template<class T>
inline string OrderList<T>::toString()
{

	stringstream ss;
	ss << "[";
	int size = this->size_;
	for (int i = 0; i < size; i++)
	{
		ss << items[i];
		if (i != size - 1)
			ss << ",";
	}
	ss << "]";
	
	return ss.str();
}

template <class T>
ostream& operator<<(ostream& os, const OrderList<T>& ol)
{

	int size = ol.size();
	{
		os << "[ ";
		for (int i = 0; i < size; i++)
		{
			os << ol.items[i] << ", "[i == size - 1];
		}
		os << "]";
	}
	return os;
}

