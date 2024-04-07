#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int t;

int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int board[52][52] = {0};
		int vis[52][52] = {0};
		int n, m, cnt;
		int res = 0;
		queue<pair<int, int>> Q;
		cin >> n >> m >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int tx, ty;
			cin >> tx >> ty;
			board[tx][ty] = 1;
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (board[j][k] == 1 && vis[j][k] == 0)
				{
					Q.push({j,k});
					res++;
					while (!Q.empty())
					{
						pair<int, int> cur = Q.front();
						Q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || ny < 0 || nx >= n || ny >= m)
								continue;
							if (vis[nx][ny] == 1 || board[nx][ny] == 0)
								continue;
							vis[nx][ny] = 1;
							Q.push({nx,ny});
						}
					}
				}
			}
		}
		cout << res << '\n';
	}
}