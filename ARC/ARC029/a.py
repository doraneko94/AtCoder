N = int(input())
t = [int(input()) for _ in range(N)]

ans = 10 ** 9
for i in range(2 ** N):
    niku1 = 0
    niku2 = 0
    for j in range(N):
        if (i >> j) & 1:
            niku1 += t[j]
        else:
            niku2 += t[j]
    if ans > max([niku1, niku2]):
        ans = max([niku1, niku2])
print(ans)