import numpy as np
q = int(input())

for _ in range(q):
    X = np.array([ord(i) for i in input()])
    Y = np.array([ord(i) for i in input()])
    NX = len(X)
    NY = len(Y)
    dp = np.zeros((NX+1,NY+1), dtype=np.int64)
    for x in range(NX):
        yes = Y == X[x]
        no = Y != X[x]
        dp[x+1][1:][yes] = dp[x][:-1][yes] + 1
        dp[x+1][1:][no] = np.maximum(dp[x][1:][no], dp[x][:-1][no])
    print(dp[NX][NY])