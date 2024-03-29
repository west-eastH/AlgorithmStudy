n = int(input())
data  = input().split()
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
move = ['R', 'D', 'L', 'U']

x, y = 1, 1
for plan in data:
    for i in range(4):
        if plan == move[i]:
            nx = x + dx[i]
            ny = y + dy[i]
    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue
    x = nx
    y = ny
print(x, y)