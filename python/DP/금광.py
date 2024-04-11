T = int(input())

for tc in range(T):
	n, m = map(int, input().split())
	arr = list(map(int, input().split()))
	d = []
	index = 0
	for j in range(n):
		d.append([x for x in arr[index:index + m]])
		index += m
	for y in range(1, m):
		for x in range(n):
			if x == 0:
				left_up = 0
			else:
				left_up = d[x - 1][y - 1]
			if x == n - 1:
				left_down = 0
			else:
				left_down = d[x + 1][y - 1]
			left = d[x][y - 1]
			d[x][y] = d[x][y] + max(left_up, left, left_down)
	result = 0
	for i in range(n):
		result = max(d[i][m - 1], result)
	print(result)
