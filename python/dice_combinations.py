n, mod = int(input()), int(1e9+7)

dp = [0]*(n+1)
dp[0] = 1
dp[1] = 1
for i in range(2, n+1):
    for j in range(1, 7):
        if i-j < 0: break
        dp[i] += dp[i-j]
    dp[i] %= mod
print(dp[-1])