from collections import deque
import sys
input = sys.stdin.readline

dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]

def bfs():
	cnt = 0
	queue = deque([(0, 0, 0)])
	visited = [[[-1, -1] for _ in range(m)] for _ in range(n)]
	visited[0][0][0] = 1	#벽을 부수지 않은 상황
	visited[0][0][1] = 1	#벽을 부수고 온 상황
	while (queue):
		x, y, wall = queue.popleft()
		if x == n -1 and y == m - 1:
			return max(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1])
		for i in range(4):
			if x + dx[i] < 0 or x + dx[i] >= n or y + dy[i] < 0 or y + dy[i] >= m:
				continue
			nx = x + dx[i]
			ny = y + dy[i]
			if visited[nx][ny][wall] == -1:
				if (graph[nx][ny] == 0):
					visited[nx][ny][wall] = visited[x][y][wall] + 1
					queue.append((nx,ny,wall))
				else:
					if wall == 0:
						visited[nx][ny][1] = visited[x][y][wall] + 1
						queue.append((nx,ny,1))
	return -1

n, m = map(int, input().split())
graph = []
for i in range(n):
	graph.append(list(map(int, input().strip())))
print(bfs())