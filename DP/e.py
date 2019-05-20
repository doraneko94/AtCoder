import numpy as np
INF = 10 ** 12

N, W = map(int, input().split(" "))
wv = np.array([[int(i) for i in input().split(" ")] for _ in range(N)])

sumv = np.sum(wv[:,1])

dp = np.zeros((N + 1, sumv + 1), dtype=np.int64)
dp[0][1:] = INF

for i in range(N):
    dp[i+1][:wv[i][1]] = dp[i][:wv[i][1]]
    dp[i+1][wv[i][1]:] = np.minimum(dp[i][wv[i][1]:], dp[i][:-wv[i][1]]+wv[i][0])

ans = 0
for v, w in enumerate(dp[N]):
    if w <= W:
        ans = max(v, ans)

print(ans)
