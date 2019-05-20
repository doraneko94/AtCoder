A, B = input().split(" ")
AB = [[int(a) for a in str(int(A)-1)], [int(b) for b in B]]
N = [len(AB[0]), len(AB[1])]
ans = []
for i in {0,1}:
    dp = [[[0] * 2 for _ in range(2)] for j in range(N[i]+1)]
    dp[0][0][0] = 1
    for j in range(N[i]):
        for small in {0, 1}:
            for cond in {0, 1}:
                if small == 0:
                    n = AB[i][j]
                    if n <= 4:
                        f = 0
                    else:
                        f = 1
                    if n != 4 and n != 9:
                        fn = 0
                    else:
                        fn = 1
                else:
                    f = 1
                    fn = 1
                    n = 9
                if n >= 1:
                    dp[j+1][1][cond] += dp[j][small][cond] * (n - 1)
                    dp[j+1][1][f] += dp[j][small][cond]
                dp[j+1][small][fn] += dp[j][small][cond]
    ans.append(dp[N[i]][0][1] + dp[N[i]][1][1])

print(ans[1]-ans[0])