#include <bits/stdc++.h>
using namespace std;
int dist[100003];

int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	queue<int> Q;
	fill(dist, dist + 100002, -1);
	dist[n] = 0;
	Q.push(n);
	while (dist[k] == -1)
	{
		int cur = Q.front();
		Q.pop();
		for (int n : {cur - 1, cur + 1, cur * 2})
		{
			if (n < 0 || n > 100000)
				continue;
			if (dist[n] >= 0)
				continue;
			dist[n] = dist[cur] + 1;
			Q.push(n);
		}
	}
	cout << dist[k];
}