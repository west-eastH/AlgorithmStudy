#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[8] = {2,2,1,-1,-2,-2,1,-1};
int dy[8] = {1,-1,2,2,1,-1,-2,-2};
int t,n;

int main (void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int dist[302][302] = {0};
		for (int i = 0; i < n; i++)
		{
			fill(dist[i], dist[i] + n, -1);
		}
		int cx,cy;
		cin >> cx >> cy;
		dist[cx][cy] = 0;
		queue<pair<int, int>> Q;
		Q.push({cx,cy});
		int fx,fy;
		cin >> fx >> fy;
		while (dist[fx][fy] == -1)
		{
			pair<int, int> cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (dist[nx][ny] >= 0)
					continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({nx,ny});
			}
		}
		cout << dist[fx][fy] << '\n';
	}
	return 0;
}