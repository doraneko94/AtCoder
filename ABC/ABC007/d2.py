A, B = input().split(" ")
AB = [[int(a) for a in str(int(A)-1)], [int(b) for b in B]]
N = [len(AB[0]), len(AB[1])]
ans = []
for i in [0, 1]:
    dp = [[[0] * 2 for _ in range(2)] for _ in range(N[i]+1)]
    dp[0][0][0] = 1
    for j, n in enumerate(AB[i]):
        if n in [4, 9]:
            dp[j+1][0][1] = 1
            dp[j+1][0][0] = 0
        else:
            dp[j+1][0][1] = dp[j][0][1]
            dp[j+1][0][0] = dp[j][0][0]
        
        dp[j+1][1][0] = dp[j][1][0] * 8 + dp[j][0][0] * n
        dp[j+1][1][1] = dp[j][1][1] * 10 + dp[j][0][1] * n + dp[j][1][0] * 2

        if dp[j][0][0] and n > 4:
            dp[j+1][1][0] -= 1
            dp[j+1][1][1] += 1
    ans.append(dp[N[i]][0][1] + dp[N[i]][1][1])
print(ans[1]-ans[0])