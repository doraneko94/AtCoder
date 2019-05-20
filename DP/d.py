import numpy as np
N, W = map(int, input().split(" "))

dp = np.zeros(W+1,dtype=int)
for i in range(N):
    w,v = map(int, input().split(" "))
    dp[w:] = np.maximum(dp[w:], dp[:-w]+v)
print(int(dp[-1]))