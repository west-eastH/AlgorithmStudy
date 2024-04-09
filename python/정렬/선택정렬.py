arr = [1,5,2,3,4,8,6,0,7,9]
for i in range(len(arr)):
	min_idx = i
	for j in range(i + 1, len(arr)):
		if arr[min_idx] > arr[j]:
			min_idx = j
	arr[i], arr[min_idx] = arr[min_idx], arr[i]
print(arr)