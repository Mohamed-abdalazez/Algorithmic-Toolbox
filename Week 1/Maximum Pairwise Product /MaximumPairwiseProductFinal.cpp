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
	//cout << "my: " << maxi.first << " " << maxi.second << endl;
	return (long long)maxi.first * maxi.second;
}

int main()
{
	long long n;
	cin >> n;
	vector<int> v(n);
	for (auto &it : v)
		cin >> it;
	cout << solve(v) << endl;
	return 0;
}
 
