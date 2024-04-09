arr = [1,5,2,3,4,8,6,0,7,9]

for i in range(1, len(arr)):
	for j in range(i, 0, -1):
		if (arr[j] < arr[j - 1]):
			arr[j], arr[j - 1] = arr[j - 1], arr[j]
		else:
			break
print(arr)