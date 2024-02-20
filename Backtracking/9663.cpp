#include <iostream>

using namespace std;
int n;
bool isused1[40];
bool isused2[40];
bool isused3[40];
int cnt;

void func(int cur)
{
	if (cur == n)
	{
		cnt++;
		return ;
	}
	for (size_t i = 0; i < n; i++)
	{
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1])
			continue;
		isused1[i] = 1;
		isused2[cur + i] = 1;
		isused3[cur - i + n - 1] = 1;
		func(cur + 1);
		isused1[i] = 0;
		isused2[cur + i] = 0;
		isused3[cur - i + n - 1] = 0;
	}
	
}

// cur + i
// 0 1 2 3 4 5 6
// 1 2 3 4 5 6 7
// 2 3 4 5 6 7 8
// 3 4 5 6 7 8 9
// 4 5 6 7 8 9 10

// cur - i + n - 1
// 4 3 2 1 0
// 5 4 3 2 1
// 6 5 4 3 2
// 7 6 5 4 3
// 8 7 6 5 4

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	func(0);
	cout << cnt << '\n';
	return 0;
}