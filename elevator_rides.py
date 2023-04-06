# UNFINISHED
import heapq
n, x = [int(i) for i in input().split()]
arr = [int(i) for i in input().split()]
h = []
path = []
def backtrack(i, total):
    if total > x: return
    heapq.heappush(h, (x-total, tuple(path)))
    for j in range(i+1, n):
        path.append(j)
        backtrack(j, total+arr[j])
        path.pop()
for i in range(n):
    path.append(i)
    backtrack(i, arr[i])
    path.pop()
seen = set()
res = 0
print(res)