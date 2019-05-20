N, D = map(int, input().split(" "))

A = 0
B = 0
C = 0

while D % 2 == 0:
    A += 1
    D //= 2
while D % 3 == 0:
    B += 1
    D //= 3
while D % 5 == 0:
    C += 1
    D //= 5

if D != 1:
    print("0")
    import sys
    sys.exit()

dp = [[[0] * (C+1) for _ in range(B+1)] for _ in range(A+1)]
dp[0][0][0] = 1
for i in range(N):
    dp2 = [[[0] * (C+1) for _ in range(B+1)] for _ in range(A+1)]
    for a in range(A+1):
        for b in range(B+1):
            for c in range(C+1):
                dp2[min(a+1, A)][b][c] += dp[a][b][c] / 6
                dp2[min(a+2, A)][b][c] += dp[a][b][c] / 6
                dp2[min(a+1, A)][min(b+1, B)][c] += dp[a][b][c] / 6
                dp2[a][min(b+1, B)][c] += dp[a][b][c] / 6
                dp2[a][b][min(c+1, C)] += dp[a][b][c] / 6
                dp2[a][b][c] += dp[a][b][c] / 6
    dp = dp2
print("{:.10f}".format(dp[-1][-1][-1]))