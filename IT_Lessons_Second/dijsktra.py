# find next alphabet permutation

arr = [2, 8, 9, 6, 7, 3, 5, 4, 1]

for i in range(len(arr) - 2, -1, -1):
    if arr[i] < arr[i + 1]:
        m = arr[i + 1]
        ind = i + 1
        for j in range(i + 1, len(arr)):
            if arr[i] < arr[j] and arr[j] < m:
                m = arr[j]
                ind = j
        arr[i], arr[ind] = arr[ind], arr[i]
        arr = arr[:i + 1] + sorted(arr[i + 1:])
        print(arr)
        break