import sys

input = sys.stdin.readline

n = int(input())
arr = []
data = dict()
_sum = 0
for _ in range(n):
    x = int(input())
    arr.append(x)
    _sum += x
    data[x] = data.get(x, 0) + 1
print(round(_sum / n))
arr.sort()
print(arr[n // 2])
_max = max(data.values())
res = []
for key, val in data.items():
    if (val == _max):
        res.append(key)
if (len(res) == 1):
    print(res[0])
else:
    print(sorted(res)[1])
print(arr[-1] - arr[0])