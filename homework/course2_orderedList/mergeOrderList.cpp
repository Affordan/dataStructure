#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vi1;
    int n, m;
    cin >> n >> m;
    int tmp = 0;
    for (int i = 0; i < n + m; i++) {
        cin >> tmp;
        vi1.push_back(tmp);
    }
    sort(vi1.begin(), vi1.end());
    for (auto v : vi1)
        cout << v << " ";

    return 0;
}
