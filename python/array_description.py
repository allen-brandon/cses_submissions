#Try in C++ to avoid TLE
n, m = (int(x) for x in input().split())
arr = [int(x) for x in input().split()]
mod = int(1e9)+7
if arr[0] == 0:
    state = [1]*(m+1)
else:
    state = [0]*(m+1)
    state[arr[0]] = 1
state[0] = 0
for i in range(1, len(arr)):
    state = [sum([state[j-1]*int(j>1), state[j], state[j+1] if j!=m else 0])%mod for j in range(m+1)]
    if arr[i]:
        state = [state[j] if j == arr[i] else 0 for j in range(m+1)]
    state[0] = 0
print(sum(state)%mod)