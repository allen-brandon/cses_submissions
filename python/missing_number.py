n = int(input())
arr = [int(x) for x in input().split()]
res = len(arr)+1
for i, x in enumerate(arr):
    res ^= x
    res ^= i+1
print(res)