#Try in C++ to avoid TLE
from collections import deque
n, m = (int(x) for x in input().split())
grid = [[0 if x == '.' else 1 for x in input()] for _ in range(n)]
res = 0
st = deque()
d = [(-1,0),(0,1),(1,0),(0,-1)]
for i in range(n):
    for j in range(m):
        if not grid[i][j]:
            st.append((i, j))
            res+=1
            while st:
                x, y = st.pop()
                grid[x][y] = 1
                for dx, dy in d:
                    if x+dx < 0 or y+dy < 0: continue
                    if x+dx == n or y+dy == m: continue
                    if grid[x+dx][y+dy]: continue
                    st.append((x+dx, y+dy))
print(res)