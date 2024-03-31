data = input()

flag = False
result = ""
start = 0
for i in range(len(data)):
	if (data[i] == '<'):
		if i != 0:
			word = data[start:i]
			result += word[::-1]
		flag = True
	elif (data[i] == '>'):
		flag = False
		result += data[i]
		start = i + 1
		continue
	if flag == True:
		result += data[i]
		continue
	else:
		if (data[i] == " "):
			word = data[start:i]
			result += word[::-1] + " "
			start = i + 1
		elif i == len(data) - 1:
			word = data[start:]
			result += word[::-1]

print(''.join(result))