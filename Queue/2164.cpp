#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;
	int n;
	cin >> n;
	int i = 1;
	while (i <= n)
	{
		Q.push(i);
		i++;
	}
	while (1)
	{
		if (Q.size() == 1)
			break;
		Q.pop();
		if (Q.size() == 1)
			break;
		Q.push(Q.front());
		Q.pop();
	}
	cout << Q.front();
}
