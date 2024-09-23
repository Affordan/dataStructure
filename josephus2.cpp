#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int* ai = new int[n+1];
	int* res = new int[n+1];
	for (int i = 1; i <= n; i++) ai[i] = i;

	int cnt = 1;
	int size = 0;
	int move = 1;

	//not filled 
	while (size!=n)
	{
		if (ai[move] == 0) continue;
		if (cnt == k)
		{
			res[++size] = ai[move];
			
			move++;
			cnt = 1;
		}
		else
		{
			move++;
			cnt++;
		}
		if (move > n)move = 1;
	}


	return 0;
}