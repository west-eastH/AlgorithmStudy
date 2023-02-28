#include <stdio.h>

int main ()
{
	int n;
	int arr[100001] = {0};
	int result[2000001] = {0};
	int i = 0;
	int num;
	int x;
	int cnt = 0;
	scanf("%d", &n);
	while (i < n)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	scanf("%d", &x);
	i = 0;
	while (i < n)
	{
		if(result[x - arr[i]] == 1)
			cnt++;
		result[arr[i]] = 1;
		i++;
	}
	printf("%d", cnt);
	return 0;
}