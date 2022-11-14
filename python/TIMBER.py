M, N = map(int, input().split())
array = []
for i in range(M):
    array.append(list(map(int, input().split())))
dp = [[0 for i in range(N + 1)] for j in range(M + 1)]
sm = 0
for i in range(1, N + 1):
    sm += array[0][i - 1]
    dp[1][i] = sm
sm = 0
for i in range(1, M + 1):
    sm += array[i - 1][0]
    dp[i][1] = sm
C = int(input())
queries = []
mxX = 0
mxY = 0
for i in range(C):
    queries.append(list(map(int, input().split())))
    mxX = max(mxX, queries[-1][2])
    mxY = max(mxY, queries[-1][3])

for i in range(2, mxX + 1):
    for j in range(2, mxY + 1):
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + array[i - 1][j - 1]

for i in range(C):
    x1, y1, x2, y2 = queries[i]
    print(dp[x2][y2] - (dp[x2][y1 - 1] + dp[x1 - 1][y2] - dp[x1- 1][y1 - 1]))