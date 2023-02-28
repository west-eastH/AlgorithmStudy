#include <bits/stdc++.h>
using namespace std;

int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		stack<char> s;
		int check = 1;
		string str;
		cin >> str;
		for (char c : str)
		{
			if (c == '(')
			{
				s.push(c);
			}
			else if(c == ')')
			{
				if (s.empty())
				{
					check = 0;
					break;
				}
				if (s.top() == '(')
				{
					s.pop();
				}
				else
				{
					check = 0;
					break;
				}
			}
		}
		if (s.empty() && check)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}