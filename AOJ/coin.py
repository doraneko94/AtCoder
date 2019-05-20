n, m = map(int, input().split(" "))
C = map(int, input().split(" "))

dp = [10**9 for _ in range(n+1)]
dp[0] = 0
for c in C:
    for p in range(c, n+1):
        dp[p] = min([dp[p], dp[p-c]+1])

print(dp[n])