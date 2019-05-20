S = input()
N = len(S)
ans = 0
for i in range(2 ** (N-1)):
    p = 0
    for j in range(N-1):
        if (i >> j) & 1:
            ans += int(S[p:j+1])
            p = j+1
    ans += int(S[p:])
print(ans)