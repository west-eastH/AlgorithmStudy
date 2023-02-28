#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int mystack[1000005];
int pos = 0;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	int x;
	string op;
	while (num--)
	{
		cin >> op;
		if (op.compare("push") == 0)
		{
			cin >> x;
			mystack[pos] = x;
			pos++;
		}
		else if (op.compare("top") == 0)
		{
			if (pos == 0)
				cout << -1 << '\n';
			else
				cout << mystack[pos - 1] << '\n';
		}
		else if (op.compare("size") == 0)
		{
			cout << pos << '\n';
		}
		else if (op.compare("empty") == 0)
		{
			if (pos == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else
		{
			if (pos == 0)
				cout << -1 << '\n';
			else
			{
				pos--;
				cout << mystack[pos] << '\n';
			}
		}
	}
	
}