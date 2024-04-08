from collections import deque
import sys
import copy

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n, m = map(int, input().split())
graph = []
visited = []
for i in range(n):
	graph.append(list(map(int, input().split())))
	visited.append([x > 0 for x in graph[i]])


dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

def bfs():
	copy_map = copy.deepcopy(graph)
	queue = deque()
	for i in range(n):
		for j in range(m):
			if (copy_map[i][j] == 2):
				queue.append((i, j))
	while(queue):
		x, y = queue.popleft()
		for i in range(4):
			if x + dx[i] < 0 or x + dx[i] >= n or y + dy[i] < 0 or y +dy[i] >= m:
				continue
			nx = x + dx[i]
			ny = y + dy[i]
			if copy_map[nx][ny] == 0:
				copy_map[nx][ny] = 2
				queue.append((nx, ny))
		
	global result
	count = 0
	for i in range(n):
		for j in range(m):
			if (copy_map[i][j] == 0):
				count += 1
	result = max(result, count)

def func(cnt):
	if (cnt == 3):
		bfs()
		return
	for i in range(n):
		for j in range(m):
			if graph[i][j] == 0:
				graph[i][j] = 1
				func(cnt + 1)
				graph[i][j] = 0

result = 0
func(0)
print(result)