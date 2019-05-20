import numpy as np
N, K = map(int, input().split(" "))
H = np.array([int(i) for i in input().split(" ")])

cost = np.array([0] + [10**9 for _ in range(N-1)])
for i in range(1,N):
    cost[i] = np.min(cost[max(0,i-K):i] + np.abs(H[max(0,i-K):i] - H[i]))

print(cost[-1])