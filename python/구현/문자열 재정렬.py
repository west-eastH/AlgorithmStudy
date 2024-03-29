data = input()
data = sorted(list(data))
num = 0
for i in range(len(data)):
    if data[i] > '9':
        result = data[i:]
        break
    num += int(data[i])
if num != 0:
	result += str(num)
print(''.join(result))