#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int maxBit(const vector<int>& v)
{
	auto maxv = *max_element(v.begin(), v.end());

	int cnt = 0;
	while (maxv != 0)
	{
		maxv /= 10;
		cnt++;
	}
	return cnt;
}

void RadixSort(vector<int>& v)
{
	int d = maxBit(v);
	int size = v.size();
	int* count = new int[10];
	int* tmp = new int[size];


	int radix = 1;
	// d times sort 
	for (int i = 0; i < d; i++)
	{
		for (int i = 0; i < 10; i++) count[i] = 0;
		for (int i = 0; i < size; i++)
		{
			int k = (v[i] / radix) % 10;	// compared number;
			count[k]++;
		}

		for (int i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (int i = size - 1; i >= 0; i--)
		{
			int k = (v[i] / radix) % 10;
			tmp[count[k] - 1] = v[i];
			count[k]--;
		}

		for (int i = 0; i < size; i++)
		{
			v[i] = tmp[i];
		}
		for (int i = 0; i < size; i++)
		{
			cout << v[i] <<" \n"[i == size - 1];
		}
		radix *= 10;

	}


	delete[] count;
	delete[] tmp;

	return;
}

int main()
{
	int t;
	cin >> t;
	vector<int> vi(t, 0);
	for (int i = 0; i < t; i++) cin >> vi[i];
	RadixSort(vi);

	return 0;
}