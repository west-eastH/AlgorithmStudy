#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int dist[502][502];
	int n,m;
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	cin >> n >> m;
	string str[502];
	for(int i = 0; i < n; i++)
	{
		cin >> str[i];

		fill(dist[i], dist[i] + m, -1);
	}
	queue<pair<int, int>> Q;
	dist[0][0] = 0;
	Q.push({0,0});
	while(!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for(int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (dist[nx][ny] != -1 || str[nx][ny] != '1')
				continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx,ny});
		}
	}
	cout << dist[n - 1][m - 1] + 1;
	return 0;
}
