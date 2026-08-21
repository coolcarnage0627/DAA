import random
import time
import matplotlib.pyplot as plt


def linear_search(arr, key):
    for x in arr:
        if x == key:
            return True
    return False


def binary_search(arr, key):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return True
        if arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return False


sizes = [100, 200, 500, 1000, 2000, 5000]
linear_times = []
binary_times = []

for n in sizes:
    arr = [random.randint(1, 10000) for _ in range(n)]
    arr.sort()
    key = arr[-1]

    start = time.perf_counter()
    linear_search(arr, key)
    end = time.perf_counter()
    linear_times.append((end - start) * 1000)

    start = time.perf_counter()
    binary_search(arr, key)
    end = time.perf_counter()
    binary_times.append((end - start) * 1000)

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

print('Array Size | Linear Search (ms) | Binary Search (ms)')
for n, ltime, btime in zip(sizes, linear_times, binary_times):
    print(f'{n:>10} | {ltime:>18.6f} | {btime:>18.6f}')
