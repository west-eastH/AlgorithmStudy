from collections import deque
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())

graph = [[] for _ in range(n + 1)]
visited = [-1 for _ in range(n + 1)]

a, b = map(int, input().split())
m = int(input())

for _ in range(m):
	x, y = map(int, input().split())
	graph[x].append(y)
	graph[y].append(x)


queue = deque([a])
visited[a] += 1
while queue:
	t = queue.popleft()
	if t == b:
		break
	for i in graph[t]:
		if visited[i] == -1:
			queue.append(i)
			visited[i] = visited[t] + 1
if visited[b] > 0:
	print(visited[b])
else:
	print(-1)