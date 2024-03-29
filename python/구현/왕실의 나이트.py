cur = input()
dx = [2, 1, -1, -2, -2, -1, 1, 2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]
col = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
x, y = int(cur[1]), col.index(cur[0]) + 1
count = 0
for i in range(8):
    nx = x + dx[i]
    ny = y + dy[i]
    if nx < 1 or ny < 1 or nx > 8 or ny > 8:
        continue
    count += 1
print(count)