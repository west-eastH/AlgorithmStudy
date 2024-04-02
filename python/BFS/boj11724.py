from collections import deque

def bfs(x, y) :
	queue.append(graph[1])

n, m = map(int, input().split())

graph = []
graph.append((0,0))
for i in range(m):
	graph.append(tuple(map(int, input().split())))

queue = deque()
print(bfs(graph[1]))