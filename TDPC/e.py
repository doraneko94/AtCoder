MOD = 10 ** 9 + 7

D = int(input())
N = [int(i) for i in str(10**10001)]
L = len(N)

dp = [[[0] * D for _ in range(2)] for _ in range(L+1)]
dp[0][0][0] = 1
for i in range(L):
    for small in {0, 1}:
        for j in range(D):
            if small == 0:
                for n in range(N[i]):
                    dp[i+1][1][(j+n)%D] += dp[i][0][j] % MOD
                dp[i+1][0][(j+N[i])%D] += dp[i][0][j] % MOD
            else:
                for n in range(10):
                    dp[i+1][1][(j+n)%D] += dp[i][1][j] % MOD
print((dp[L][1][0]+dp[L][0][0]-1)%MOD)