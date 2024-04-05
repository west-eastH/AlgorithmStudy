from collections import deque
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
	u, v = map(int, input().split())
	graph[u].append(v)
	graph[v].append(u)
 
visited = [False] * (n + 1)
count = 0

def bfs(i):
	queue = deque([i])
	visited[i] = True
	
	while(queue):
		v = queue.popleft()
		for i in graph[v]:
			if (visited[i] == False):
				visited[i] = True
				queue.append(i)


for i in range(1, n + 1):
	if (visited[i] == False):
		count += 1
		bfs(i)
print(count)