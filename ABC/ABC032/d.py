N, W = map(int, input().split(" "))
import numpy as np
vw = np.array([[int(i) for i in input().split(" ")] for _ in range(N)])
vmax = np.max(vw[:,0])
wmax = np.max(vw[:,1])
if vmax <= 1000:
    sumv = np.sum(vw[:,0])
    dp = np.array([[10**12] * (sumv+1) for _ in range(N+1)])
    dp[0][0] = 0
    for i in range(N):
        dp[i+1][:vw[i][0]] = dp[i][:vw[i][0]]
        dp[i+1][vw[i][0]:] = np.minimum(dp[i][vw[i][0]:], dp[i][:-vw[i][0]] + vw[i][1])
    maxval = 0
    for i in range(sumv+1):
        if dp[N][i] <= W:
            maxval = i
    print(maxval)
elif wmax <= 1000:
    dp = np.zeros(W+1)
    for i in range(N):
        dp[vw[i][1]:] = np.maximum(dp[vw[i][1]:], dp[:-vw[i][1]] + vw[i][0])
    print(int(np.max(dp)))
else:
    maxval = 0
    for i in range(2**N):
        val = 0
        wei = 0
        for j in range(N):
            if (i >> j) & 1:
                val = vw[j][0]
                wei = vw[j][1]
        if wei <= W and val > maxval:
            maxval = val
    print(maxval)