#include <bits/stdc++.h>
using namespace std;

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	while (num--)
	{
		string s;
		cin >> s;
		list<char> L;
		list<char>::iterator t = L.end();
		for (char c : s)
		{
			if (c == '<')
			{
				if (t != L.begin())
					t--;
			}
			else if (c == '>')
			{
				if (t != L.end())
					t++;
			}
			else if (c == '-')
			{
				if (t != L.begin())
				{
					t--;
					t = L.erase(t);
				}
			}
			else
			{
				L.insert(t, c);
			}
		}
		for (list<char>::iterator t = L.begin(); t != L.end(); t++)
			cout << *t;
		cout << '\n';
	}
	return 0;
}