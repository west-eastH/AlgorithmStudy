import sys
input = sys.stdin.readline

n, m = map(int, input().split())
po = []
for i in range(n):
	po.append(input().strip())
for i in range(m):
	word = input().strip()
	if word.isdigit():
		print(po[int(word) - 1])
	else:
		print(po.index(word) + 1)