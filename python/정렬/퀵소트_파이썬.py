arr = [1,5,2,3,4,8,6,0,7,9]

def quick_sort(arr):
	if (len(arr) <= 1):
		return arr
	pivot = arr[0]
	tail = arr[1:]
	left_side = [x for x in tail if x <= pivot]
	right_side = [x for x in tail if x > pivot]

	return quick_sort(left_side) + [pivot] + quick_sort(right_side)

print(quick_sort(arr))