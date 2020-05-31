from bisect import bisect_left, bisect_right

arr = [1, 3, 5, 6, 7, 9]
print(bisect_left(arr, 4))
print(bisect_left(arr, 3))
print(bisect_left(arr, -4))
print(bisect_left(arr, 9))
print(bisect_left(arr, 10))
print('-' * 20)
print(bisect_right(arr, 4))
print(bisect_right(arr, 3))
print(bisect_right(arr, -4))
print(bisect_right(arr, 9))
print(bisect_right(arr, 10))