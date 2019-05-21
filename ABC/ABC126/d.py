N = int(input())
con = [set() for _ in range(N)]
for i in range(N-1):
    u, v, w = map(int, input().split(" "))
    con[u-1].add((v-1, w))
    con[v-1].add((u-1, w))

dp = [-1 for _ in range(N)]
dp[0] = 0

def solve(x):
    for i, w in con[x]:
        if dp[i] < 0:
            if w % 2 == 0:
                dp[i] = dp[x]
            else:
                if dp[x] == 1:
                    dp[i] = 0
                else:
                    dp[i] = 1
            solve(i)
    return

solve(0)
if sum(dp) == 0:
    dp[-1] = 1
for i in range(N):
    print(dp[i])