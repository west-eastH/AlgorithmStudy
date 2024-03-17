#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;
	int n;
	int add;
	string op;
	cin >> n;
	while (n--)
	{
		cin >> op;
		if (op == "push")
		{
			cin >> add;
			Q.push(add);
		}
		else if (op == "pop")
		{
			if (Q.empty())
				cout << -1 << '\n';
			else
			{
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (op == "size")
			cout << Q.size() << '\n';
		else if (op == "empty")
		{
			if (Q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(op == "front")
		{
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.front() << '\n';
		}
		else if (op == "back")
		{
			if (Q.empty())
				cout << -1 << '\n';
			else
				cout << Q.back() << '\n';
		}
	}
}