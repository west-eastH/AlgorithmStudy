#include <bits/stdc++.h>
using namespace std;
int result[2]; //result[0] = 0 개수, result[1] = 1 개수
int board[130][130];

void rec(int x_start, int x_end, int y_start, int y_end, int num)
{
	if(x_start + 1 == x_end)
	{
		if (board[x_start][y_start] == num)
			result[num]++;
		return;
	}
	int check = 1;
	for (int i = x_start; i < x_end; i++)
	{
		for (int j = y_start; j < y_end; j++)
		{
			if (board[i][j] != num)
				check = 0;
		}
	}
	if (check == 1)
	{
		result[num]++;
		return;
	}
	int x_half = x_start + (x_end - x_start) / 2;
	int y_half = y_start + (y_end - y_start) / 2;
	rec(x_start, x_half, y_start, y_half, num);
	rec(x_start, x_half, y_half, y_end, num);
	rec(x_half, x_end, y_start, y_half, num);
	rec(x_half, x_end, y_half, y_end, num);
}

int main ()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}
	rec(0, n, 0, n, 0);
	rec(0, n, 0, n, 1);
	cout << result[0] << '\n' << result[1];
	return 0;
}