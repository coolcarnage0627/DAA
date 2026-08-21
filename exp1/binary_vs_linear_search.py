import random
import time
import matplotlib.pyplot as plt


def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1


def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1


def generate_sorted_array(n):
    arr = [random.randint(1, 1000000) for _ in range(n)]
    arr.sort()
    return arr


def measure_time(search_func, arr, target):
    start = time.perf_counter()
    search_func(arr, target)
    end = time.perf_counter()
    return (end - start) * 1000  # milliseconds


sizes = [100, 200, 400, 800, 1600, 3200, 6400, 12800]
linear_times = []
binary_times = []

for n in sizes:
    arr = generate_sorted_array(n)
    target = arr[-1]  # worst-case for linear search, average-case for binary search if target in middle not last

    linear_times.append(measure_time(linear_search, arr, target))
    binary_times.append(measure_time(binary_search, arr, target))

plt.figure(figsize=(10, 6))
plt.plot(sizes, linear_times, label='Linear Search', marker='o', color='blue')
plt.plot(sizes, binary_times, label='Binary Search', marker='s', color='red')
plt.xlabel('Array Size')
plt.ylabel('Time (ms)')
plt.title('Linear Search vs Binary Search Time Comparison')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()

print("Array Size | Linear Search Time (ms) | Binary Search Time (ms)")
for n, lt, bt in zip(sizes, linear_times, binary_times):
    print(f"{n:>10} | {lt:>22.6f} | {bt:>22.6f}")
