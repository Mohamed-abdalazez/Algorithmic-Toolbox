#include "bits/stdc++.h"

using namespace std;

long long solve(vector<int> v)
{
	int idxvis[v.size()];
	memset(idxvis, 0, sizeof(idxvis));
	long long result = -1;
	pair<int, int> maxi;
	maxi.first = v[0];
	maxi.second = v[1];
	idxvis[0] = idxvis[1] = 1;
	for (int i = 2; i < v.size(); i++)
	{
		if (v[i] < maxi.first && v[i] < maxi.second)
			continue;
		if (v[i] == max(maxi.first, maxi.second) && !idxvis)
		{
			idxvis[i] = 1;
			maxi.first = maxi.second = v[i];
			continue;
		}
		idxvis[i] = 1;
		int a[] = {v[i], maxi.first, maxi.second};
		sort(a, a + 3);
		maxi.first = a[2];
		maxi.second = a[1];
	}
	cout << "my: " << maxi.first << " " << maxi.second << endl;
	return (long long)maxi.first * maxi.second;
}
long long MaxPairwiseProduct(vector<int> numbers)
{
	int n = numbers.size();
	int max_idxI = -1;
	for (int i = 0; i < n; i++)
	{
		if ((max_idxI == -1) || (numbers[i] > numbers[max_idxI]))
			max_idxI = i;
	}
	int max_idxII = -1;
	for (int j = 0; j < n; j++)
	{
		if ((j != max_idxI) && ((max_idxII == -1) || (numbers[j] > numbers[max_idxII])))
			max_idxII = j;
	}
	cout << "he: " << numbers[max_idxI] << " " << numbers[max_idxII] << endl;
	return (long long)numbers[max_idxI] * numbers[max_idxII];
}

int main()
{
	while (true)
	{
		int n = rand() % 100 + 2;
		cout << n << endl;
		vector<int> a;
		for (int i = 0; i < n; i++)
		{
			a.push_back(rand() % 100000);
		}
		for (auto it : a)
			cout << it << " ";
		cout << endl;
		long long res1 = solve(a);
		long long res2 = MaxPairwiseProduct(a);
		if (res1 != res2)
		{
			cout << "WA: " << res1 << " " << res2 << endl;
			break;
		}
		else
		{
			cout << "ok" << endl;
		}
	}

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &it : v)
		cin >> it;
	cout << solve(v) << endl;
	cout << MaxPairwiseProduct(v) << endl;
	return 0;
}
