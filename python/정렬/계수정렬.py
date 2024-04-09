arr = [1,5,2,3,4,8,6,0,2,1,6,2,7,8,5,7,9]

count = [0] * (max(arr) + 1)
for i in range(len(arr)):
	count[arr[i]] += 1

for i in range(len(count)):
	for j in range(count[i]):
		print(i, end=" ")