#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int n, k, sum, cnt;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> n >> k;
	sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		while (sum + arr[i] <= k)
		{
			sum += arr[i];
			cnt++;
		}
	}
	cout << cnt << '\n';
    return 0;
}