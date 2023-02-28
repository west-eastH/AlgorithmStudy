#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<int> Q;
	int n;
	int add;
	string op;
	cin >> n;
	while (n--)
	{
		cin >> op;
		if (op == "push_front")
		{
			cin >> add;
			Q.push_front(add);
		}
		else if (op == "push_back")
		{
			cin >> add;
			Q.push_back(add);
		}
		else if (op == "pop_front")
		{
			if (Q.empty())
				cout << -1 << '\n';
			else
			{
				cout << Q.front() << '\n';
				Q.pop_front();
			}
		}
		else if (op == "pop_back")
		{
			if (Q.empty())
				cout << -1 << '\n';
			else
			{
				cout << Q.back() << '\n';
				Q.pop_back();
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