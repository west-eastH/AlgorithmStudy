#include <string.h>
#include <stdio.h>

char str1[1001];
char str2[1001];
int n;

int main()
{
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	int k = 0;
	int check = 0;
	while (i < n)
	{
		scanf("%s", str1);
		scanf("%s", str2);
		int str1len = strlen(str1);
		int str2len = strlen(str2);

		int arr1[26] = {0};
		int arr2[26] = {0};
		check = 0;
		j = 0;
		while (j < str1len)
		{
			arr1[str1[j] - 'a']++;
			j++;
		}
		k = 0;
		while (k < str2len)
		{
			arr2[str2[k] - 'a']++;
			k++;
		}
		j = 0;
		while (j < 26)
		{
			if(arr1[j] != arr2[j])
			{
				check = 1;
				break;
			}
			j++;
		}
		if (check == 1)
			printf("Impossible\n");
			
		else
			printf("Possible\n");

		i++;
	}
	return 0;
}