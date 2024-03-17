#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (1)
	{
		string str;
		stack<char> st;
		int check = 1;
		getline(cin, str);
		if (str == ".")
			break;
		int i = 0;
		while (str[i] != '.')
		{
			if (str[i] == '(' || str[i] == '[')
			{
				st.push(str[i]);
			}
			else if (str[i] == ')' || str[i] == ']')
			{
				if (st.empty())
				{
					check = 0;
					break;
				}
				if ((st.top() == '(' && str[i] == ')')
				|| (st.top() == '[' && str[i] == ']'))
					st.pop();
				else
				{
					check = 0;
					break;
				}
			}
			i++;
		}
		if (check && st.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}