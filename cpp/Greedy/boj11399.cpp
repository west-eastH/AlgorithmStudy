#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int result = arr[0];
	for (int i = 1; i < n; i++)
	{
		arr[i] = arr[i - 1] + arr[i];
		result += arr[i];
	}
	cout << result;
	return 0;
}

