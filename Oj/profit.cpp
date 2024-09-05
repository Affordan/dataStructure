#include <iostream>
#include <vector>
using namespace std;


int main()
{

    int profit = 0;
    int minv = 0;
    int t = 0;
    int n = 0;
    cin >> n;
    vector<int> vi;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        vi.push_back(tmp);
    }

    minv = vi[0];
    for (int i = 1; i < n; i++)
    {
        t = vi[i] - minv;
        if (t > profit)
            profit = t;
        if (vi[i] < minv)
            minv = vi[i];
    }

    cout << profit << endl;

    return 0;
}