import numpy as np

D, N = map(int, input().split(" "))
T = [int(input()) for _ in range(D)]
ABC = np.array([[int(i) for i in input().split(" ")] for _ in range(N)])

def MaxMin(a):
    return [np.max(a), np.min(a)]

maxmin = [MaxMin(ABC[(ABC[:,0] <= t) & (ABC[:,1] >= t)][:,2]) for t in T]
#dp = [[-1]*N for _ in range(D)]
dp = [[-1]*2 for _ in range(D)]
dp[0] = [0, 0]
for i in range(1,D):
    for j in range(2):
        for k in range(2):
            dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(maxmin[i-1][k] - maxmin[i][j]))
print(max(dp[D-1]))