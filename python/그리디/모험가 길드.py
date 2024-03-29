n = int(input())
list = list(map(int, input().split()))
result = 0
count = 0
list.sort()
for i in list:
    count += 1
    if count >= i:
        result += 1
        count = 0
print(result)