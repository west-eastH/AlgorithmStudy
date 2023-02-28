#include <bits/stdc++.h>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	while (n--)
	{
		string str;
		cin >> str;
		stack<char> s;
		for (char c : str)
		{
			if (s.empty())
				s.push(c);
			else
			{
				if (s.top() == c)
					s.pop();
				else
					s.push(c);
			}
		}
		if (s.empty())
			cnt++;
	}
	cout << cnt;
	return 0;
}