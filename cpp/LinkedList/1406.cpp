#include <bits/stdc++.h>
using namespace std;

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	list<char> L;
	for (auto c : s)
		L.push_back(c);
	list<char>::iterator cursor = L.end();
	int cnt;
	cin >> cnt;
	char op;
	char add;
	while (cnt--)
	{
		cin >> op;
		if (op == 'P')
		{
			cin >> add;
			L.insert(cursor, add);
		}
		else if (op == 'L')
		{
			if (cursor != L.begin())
				cursor--;
		}
		else if (op == 'D')
		{
			if (cursor != L.end())
				cursor++;
		}
		else
		{
			if (cursor != L.begin())
			{
				cursor--;
				cursor = L.erase(cursor);
			}
		}
	}

	for (list<char>::iterator t = L.begin(); t != L.end(); t++)
		cout << *t;
	
	return 0;
}