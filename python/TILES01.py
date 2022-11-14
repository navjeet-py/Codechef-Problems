mod = 15746
N = int(input())
dp = [1, 1, 2]
for i in range(N):
    dp.append((dp[-1]+dp[-2]) % mod )
print(dp[N])