#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template <class T> class CLList {
private:
    class Node {
    public:
        Node(const T& v) :prev(nullptr),next(nullptr), items(v) {};
        Node(const T& v,  Node* n) :items(v) {
            this->next = n->next;
            n->next = this;
        };
        Node( Node* p, const T& v, Node* n):items(v)
        {
            p->next = this;
            this->prev = p;
            n->prev = this;
            this->next = n;
        };

        T items;
        Node* prev; //really bother me.
        Node* next;
    };


private:
    Node* sentinel;
    int size_;

public:
    CLList() :size_(0) { sentinel = new Node(99999999); sentinel->prev = sentinel; sentinel->next = sentinel; };
    bool empty()
    {
        return size_ == 0;
    }
    int size() { return size_; }
    // void insert(int pos, T value);
    void push_bacK(T value)
    {
       new Node(sentinel->prev,value,sentinel);
        //consider empty()
       /* if (empty())
        {
            currNode->next = transNode;
            transNode->next = sentinel;
            size_++;
            return;
        }*/
        size_++;
        return;
    }
    T remove(int pos) {
        Node* currNode = sentinel;
        for (int i = 0; i < pos; i++) currNode = currNode->next;

        Node* transNode = currNode->next;
        currNode->next = transNode->next;
        delete transNode;
        transNode = nullptr;
        size_--;

    };

    T remove(Node* node)
    {
        int tmp = node->items;
        Node* transNode = node;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        tmp = node->items;
        node = node->next;
        delete transNode;
        transNode = nullptr;
        size_--;
        return tmp;
       
    }

    string toString()
    {
        if (empty())
            return"[]";
     
        stringstream ss;
        ss << "[";

        Node* currNode = sentinel->next;
        while (currNode != sentinel)
        {
            ss << currNode->items << ",]"[(currNode->next==sentinel)];
            currNode = currNode->next;
        }
        return ss.str();

    }

    vector<int> josephus( int m) {
        vector<int> vi;

        int cnt = 1;
        Node* currNode = sentinel->next;
        while (size_ != 1)
        {
           // cout << "cnt: " << cnt << toString() << endl;
            if (currNode == sentinel)
            {
                currNode = currNode->next;
                continue;
            }
            if (cnt == m)
            {

               // to be optimized.
               // vi.push_back(remove(currNode));
                vi.push_back(currNode->items);
                Node* tmpNode = currNode;
                currNode = currNode->next;
                tmpNode->prev->next = tmpNode->next;
                tmpNode->next->prev = tmpNode->prev;
                delete tmpNode;
                tmpNode = nullptr;
                size_--;

                //cout << "remove: " << endl;
                cnt = 1;
            }
            else
            {
                currNode = currNode->next;
                cnt++;
            }
        }
        vi.push_back(sentinel->next->items);
        return vi;
    }


};



int main() {
    CLList<int> clist;
    int n = 0, k = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) clist.push_bacK(i);
  //  cout << clist.toString() << endl;

    vector<int> res = clist.josephus( k);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1) cout << "->";
    }
    //cout<<endl << clist.toString() << endl;
    return 0;
}