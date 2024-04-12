n = int(input())
arr = [0, 0, 0] * (n + 5)
for i in range(1, n + 1):
	arr[i] = list(map(int, input().split()))

d = [[0 for i in range(3)] for j in range(n + 5)]
d[1][0] = arr[1][0]
d[1][1] = arr[1][1]
d[1][2] = arr[1][2]
for i in range(2, n + 1):
	d[i][0] = min(d[i - 1][1] + arr[i][0], d[i - 1][2] + arr[i][0])
	d[i][1] = min(d[i - 1][0] + arr[i][1], d[i - 1][2] + arr[i][1])
	d[i][2] = min(d[i - 1][0] + arr[i][2], d[i - 1][1] + arr[i][2])

print(min(d[n]))