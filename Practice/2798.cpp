#include <bits/stdc++.h>
using namespace std;

int arr[105];
int card[3];
int n,m;
int result = 0;
int MX = 0;

void dfs(int start, int depth)
{
	if (depth == 3)
	{
		int i = 0;
		while (i < 3)
		{
			result += card[i];
			i++;
		}
		if (result >= MX && result <= m)
			MX = result;
		result = 0;
		return;
	}
	else
	{
		while (start < n)
		{
			card[depth] = arr[start];
			dfs(start + 1, depth + 1);
			start++;
		}

	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int i = 0;
	while (i < n)
	{
		cin >> arr[i];
		i++;
	}
	dfs(0, 0);
	cout << MX;
}