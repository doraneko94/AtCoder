import numpy as np
INF = 10**12

W = int(input())
N, K = map(int, input().split(" "))
AB = np.array([[int(i) for i in input().split(" ")] for _ in range(N)])
Bsum = np.sum(AB[:,1])

dp = np.zeros((N+1, Bsum+1, K+1))
dp[0] = INF
dp[0][0][0] = 0

for i, (a, b) in enumerate(AB):
    dp[i+1][:b] = dp[i][:b]
    dp[i+1][b:][:,0] = dp[i][b:][:,0]
    dp[i+1][b:][:,1:] = np.minimum(dp[i][b:][:,1:], dp[i][:-b][:,:K] + a)

ans = 0
for v, ws in enumerate(dp[N]):
    if min(ws) <= W:
        ans = max(ans, v)
        
print(ans)