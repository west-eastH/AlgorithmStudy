n = int(input())

my_list = []
for _ in range(n):
    w,h = map(int, input().split())
    my_list.append((w, h))
for i in my_list :
    rank = 1
    for j in my_list:
        if i[0] < j[0] and i[1] < j[1]:
            rank += 1
    print(rank, end=" ")