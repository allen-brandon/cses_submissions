n = int(input())
arr = [int(x) for x in input().split()]
res = 0
for i in range(1, len(arr)):
    res += max(0, arr[i-1]-arr[i])
    arr[i] = max(arr[i], arr[i-1])
print(res)