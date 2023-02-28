#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n,m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main (void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cnt=0, mx=0, MX = 0;
	cin >> n >> m;
	int i = 0;
	int j = 0;
	while(i < n)
	{
		j = 0;
		while(j < m)
		{
			cin >> board[i][j];
			j++;
		}
		i++;
	}
	queue<pair<int, int>> Q;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			if (vis[i][j] != 1 && board[i][j] == 1)
			{
				vis[i][j] = 1;
				Q.push({i, j});
				mx = 0;
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();
					Q.pop();
					mx++;
					for(int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (vis[nx][ny] == 1 || board[nx][ny] != 1)
							continue;
						vis[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
				if (mx >= MX)
					MX = mx;
				cnt++;
			}
			j++;
		}
		i++;
	}
	cout << cnt << '\n' << MX;
	
	return 0;
}
