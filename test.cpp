#include "LinearList/CLList.h"
#include <vector>
using  namespace std;

vector<int> josepus(int n, int k, CLList<int>& clist)
{
	vector<int> vi;
	int cnt = 1;
	int move = 1;
	while (clist.size() != 1)
	{
		if (cnt == k)
		{
			vi.push_back(clist[move]);
			clist.remove(move);
			cnt = 1;
			move++;
		}
		else
		{
			cnt++;
			move++;
		}
	}



}


int main()
{
	CLList<int> clist;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) clist.push_back(i);

}