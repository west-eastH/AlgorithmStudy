n = int(input())

result = dict()
for i in range(n):
    x, y = map(int, input().split())
    for j in range(x, x + 10):
        for k in range(y, y + 10):
            if j < 100 and k < 100:
                result[(j, k)] = 1
print(len(result))