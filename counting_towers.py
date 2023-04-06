# UNFINISHED
from functools import cache
import time
cases = int(input())

@cache
def solve(x, y):
    if x == 0 or y == 0: return 1
    #can always be 1 block
    res = 0
    #fill with y-wide blocks
    for i in range(x):
        res += solve(i, y)
    if y == 1: return res
    for i in range(x):
        print(x-i, 1)
        res += solve(i, y) * solve(x-i, 1)
    return res

for _ in range(cases):
    time.sleep(0.01)
    print(solve(int(input()), 2))