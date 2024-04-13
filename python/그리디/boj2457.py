n = int(input())

arr = []
for i in range(n):
	sm, sd, em, ed = map(int, input().split())
	arr.append([sm * 100 + sd, em * 100 + ed])

t = 301
ans = 0
while (t < 1201):
	next_t = t
	for i in range(n):
		if arr[i][0] <= t and arr[i][1] > next_t:
			next_t = arr[i][1]
	if next_t == t:
		print(0)
		exit()
	t = next_t
	ans += 1
print(ans)