#include <bits/stdc++.h>
using namespace std;

int dfs(int fir, int sec, int cnt, int print_check)
{
	if (print_check == 1)
		cout << fir << ' ';
	if (fir - sec < 0)
	{
		if (print_check == 1)
			cout << sec;
		return cnt;
	}
	else
	{
		if (print_check == 0)
			return dfs(sec, fir - sec, cnt + 1, 0);
		else
			return dfs(sec, fir - sec, cnt + 1, 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int count = 0;
	int i = 0;
	int result;
	while (i <= n)
	{
		if (count <= dfs(n, i, 2, 0))
		{
			count = dfs(n, i, 2, 0);
			result = i;
		}
		i++;
	}
	cout << count << '\n';
	int dummy = dfs(n, result, 2, 1);
	return 0;
}