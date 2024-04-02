cnt = int(input())
for i in range(cnt):
    line = list(map(int, input().split()))
    line_s = line[1:]
    result = list(filter(lambda x: x > (sum(line_s) / line[0]), line_s))
    print("{:.3f}%".format(100 * len(result) / line[0]))

