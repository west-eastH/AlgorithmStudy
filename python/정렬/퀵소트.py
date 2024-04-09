arr = [1,5,2,3,4,8,6,0,7,9]

def quick_sort(arr, start, end):
	if start >= end:
		return
	pivot = arr[start]
	left = start + 1
	right = end
	while left <= right:
		while left <= end and arr[pivot] >= arr[left]:
			left += 1
		while right > start and arr[pivot] <= arr[right]:
			right -= 1
		if left > right:
			arr[pivot], arr[right] = arr[right], arr[pivot]
		else:
			arr[left], arr[right] = arr[right], arr[left]
	quick_sort(arr, start, right - 1)
	quick_sort(arr, right + 1, end)
		

quick_sort(arr, 0, len(arr) - 1)
print(arr)