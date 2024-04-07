#include <stdio.h>

//9명 중 2명을 나머지 합 = 100
int main()
{
	int sum = 0;
	int result[7];
	int input[9];
	int i = 0;
	while (i < 9)
	{
		scanf("%d", &input[i]);
		sum += input[i];
		i++;
	}
	sum -= 100;
	i = 0;
	int j;
	int num1, num2;
	while (i < 9)
	{
		j = i + 1;
		while (j < 9)
		{
			if (input[i] + input[j] == sum)
			{
				num1 = i;
				num2 = j;
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < 7)
	{
		while (j < 9)
		{
			if (j != num1 && j != num2)
			{
				result[i] = input[j];
				j++;
				break;
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	int temp;
	while (i < 7)
	{
		j = 0;
		while (j + 1 < 7)
		{
			if (result[j] > result[j + 1])
			{
				temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 7)
	{
		printf("%d\n", result[i]);
		i++;
	}
}
