n, m = map(int, input().split())
arr = list(map(int, input().split()))
d = [0] * (n + 5)
for i in range(1, n + 1):
	d[i] = d[i - 1] + arr[i - 1]
for _ in range(m):
	i, j = map(int, input().split())
	print(d[j] - d[i - 1])