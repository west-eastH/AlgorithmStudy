n = int(input())
arr = [0] * 305
for i in range(1, n + 1):
	arr[i] = (int(input()))

d = [0] * 305
d[1] = arr[1]
d[2] = arr[1] + arr[2]
d[3] = arr[3] + max(arr[1], arr[2])
for i in range(4, n + 1):
	d[i] = arr[i] + max(d[i - 3] + arr[i - 1], d[i - 2])
print(d[n])