#include "OrderList.h"
using std::unique_ptr;
using std::endl;

int main()
{
	OrderList<int>* uol = new OrderList<int>();
	cout << " uol is empty: " << uol->empty() << endl;
	//unique_ptr<OrderList<int>> uol = std::make_unique<OrderList<int>>();
	for (int i = 0; i < 5; i++)uol->push_back(i);
	for (int i = -3; i < 0; i++) uol->push_front(i);
	cout << " uol is empty: " << uol->empty() << endl;

	cout << " uol size = " << uol->size() << endl;
	//cout << (uol) << endl;
	cout << uol->toString() << endl;
	cout << endl;

	OrderList<int> ol = OrderList<int>();
	cout << " ol is empty: " << ol.empty() << endl;
	//unique_ptr<OrderList<int>> uol = std::make_unique<OrderList<int>>();
	for (int i = 0; i < 5; i++)ol.push_back(i);
	for (int i = -3; i < 0; i++) ol.push_front(i);
	cout << " ol is empty: " << ol.empty() << endl;

	cout << " ol size = " << ol.size() << endl;
	cout << ol.toString() << endl;
	ol.remove();
	cout << "after remove the last item ol size = " << ol.size() << endl;
	cout << ol.toString() << endl;
	return 0;
}