import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())

graph = []
max_h = 0
for i in range(n):
	temp = list(map(int, input().split()))
	if max(temp) > max_h:
		max_h = max(temp)
	graph.append(temp)

result = 0

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def dfs(i, j, k):
	visited[j][k] = True
	for u in range(4):
		if j + dx[u] < 0 or j + dx[u] >= n or k + dy[u] < 0 or k + dy[u] >= n:
			continue
		nx = j + dx[u]
		ny = k + dy[u]
		if (visited[nx][ny] == True or graph[nx][ny] <= i):
			continue
		dfs(i, nx, ny)
	


for i in range(0, max_h):
	cnt = 0
	visited = [[False for _ in range(n)] for _ in range(n)]
	for j in range(n):
		for k in range(n):
			if (visited[j][k] == False and graph[j][k] > i):
				dfs(i, j, k)
				cnt += 1
	if result < cnt:
		result = cnt
print(result)