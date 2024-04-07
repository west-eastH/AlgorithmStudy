#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
string board[1002];
int dist[1002][1002];
int fire[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

int main (void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	queue<pair<int, int>> fQ;
	queue<pair<int, int>> jQ;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		fill(dist[i], dist[i] + m, -1);
		fill(fire[i], fire[i] + m, -1);
	}
	for (int i = 0; i < n; i++)
	{
		for  (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'J')
			{
				dist[i][j] = 0;
				jQ.push({i,j});
			}
			else if (board[i][j] == 'F')
			{
				fire[i][j] = 0;
				fQ.push({i,j});
			}
		}
	}
	while (!fQ.empty())
	{
		pair<int, int> cur = fQ.front();
		fQ.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (board[nx][ny] == '#' || fire[nx][ny] >= 0)
				continue;
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			fQ.push({nx,ny});
		}
	}
	while (!jQ.empty())
	{
		pair<int, int> cur = jQ.front();
		jQ.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				cout << dist[cur.X][cur.Y] + 1;
				return 0;
			}
			if (board[nx][ny] == '#' || dist[nx][ny] >= 0)
				continue;
			if (fire[nx][nx] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1)
				continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			jQ.push({nx,ny});
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}