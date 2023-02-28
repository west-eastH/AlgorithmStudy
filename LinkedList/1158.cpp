#include <bits/stdc++.h>
using namespace std;

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	list<int> L;
	list<int>::iterator t = L.begin();
	for (int i = 1; i <= n; i++)
	{
		L.push_back(i);
		if (i <= k)
			t++;
	}
	cout << '<';
	while (n--)
	{
		if (n != 0)
			cout << *t << ", ";
		else
			cout << *t << '>';
		if (t != L.end())
			t = L.erase(t);
		else
		{
			t = L.erase(t);
			t = L.begin();
		}
		if (t == L.end())
			t = L.begin();
		int i = 0;
		while (i < k - 1)
		{	
			t++;
			if (t == L.end())
				t = L.begin();
			i++;
		}
	}
}