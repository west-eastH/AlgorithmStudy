# X가 3으로 나누어 떨어지면, 3으로 나눈다.
# X가 2로 나누어 떨어지면, 2로 나눈다.
# 1을 뺀다.
import copy

n = int(input())
d = [0] * (n + 5)
arr = [[] for x in range(n + 5)]
d[1] = 0
arr[1].append(1)
for i in range(2, n + 1):
	d[i] = d[i - 1] + 1
	j = i - 1
	if (i % 2 == 0 and d[i] > d[i // 2] + 1):
		d[i] = d[i // 2] + 1
		j = i // 2
	if (i % 3 == 0 and d[i] > d[i // 3] + 1):
		d[i] = d[i // 3] + 1
		j = i // 3
	arr[i] = copy.deepcopy(arr[j])
	arr[i].append(i)
print(d[n])
for i in arr[n][::-1]:
	print(i, end=' ')