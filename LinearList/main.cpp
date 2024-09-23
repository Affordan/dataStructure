
#include "ArrayList.h"
#include "SLList.h"
#include "DLList.h"
#include "CLList.h"

int main() {

    cout << "ArrayList" << endl;
    ArrayList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    cout << list.toString() << endl;

    cout << "SLList" << endl;
    SLList<int> list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    cout << list2.toString() << endl;

    cout << "DLList" << endl;
    DLList<int> list3;
    list3.push_back(1);
    list3.push_back(2);
    list3.push_back(3);
    cout << list3.toString() << endl;

    cout << "CLList" << endl;
    CLList<int> list4;
    list4.push_back(1);
    list4.push_back(2);
    list4.push_back(3);
    cout << list4.toString() << endl;

    return 0;
}