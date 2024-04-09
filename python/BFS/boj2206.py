from collections import deque
import sys
input = sys.stdin.readline

def bfs():
	cnt = 0
	queue = deque((0,0))

	while (queue):
		u, v = queue.popleft()


def break_wall():
	for i in range(n):
		for j in range(m):
			if graph[i][j] == 1:
				graph[i][j] = 0
				bfs()
				graph[i][j] = 1
				

n, m = map(int, input().split())
graph = []
for i in range(n):
	graph.append(list(map(int, input().split())))

result = 0
break_wall()
print(result)