#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string board[102];
bool vis1[102][102];
bool vis2[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;

void bfs(int i, int j, char c, bool vis[102][102])
{
	queue<pair<int, int>> Q;
	Q.push({i,j});
	vis[i][j] = 1;
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (board[nx][ny] != c || vis[nx][ny] == 1)
				continue;
			vis[nx][ny] = 1;
			Q.push({nx,ny});
		}
	}
}

int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'R' && vis1[i][j] == 0)
			{
				cnt1++;
				bfs(i, j, 'R', vis1);
			}
			else if (board[i][j] == 'B' && vis1[i][j] == 0)
			{
				cnt1++;
				bfs(i, j, 'B', vis1);
			}
			else if (board[i][j] == 'G' && vis1[i][j] == 0)
			{
				cnt1++;
				bfs(i, j, 'G', vis1);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'R' && vis2[i][j] == 0)
			{
				cnt2++;
				bfs(i, j, 'R', vis2);
			}
			else if (board[i][j] == 'B' && vis2[i][j] == 0)
			{
				cnt2++;
				bfs(i, j, 'B', vis2);
			}
		}
	}
	cout << cnt1 << '\n' << cnt2;
}