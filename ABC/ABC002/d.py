N, M = map(int, input().split(" "))
rel = [[i] for i in range(N+1)]
for _ in range(M):
    x, y = map(int, input().split(" "))
    rel[x].append(y)
    rel[y].append(x)
ans = 0
for i in range(2 ** N):
    lst = []
    for j in range(N):
        if (i >> j) & 1:
            lst.append(j+1)
    key = 0
    for j in lst:
        if set(lst) <= set(rel[j]):
            pass
        else:
            key = 1
    if key == 0 and len(lst) > ans:
        ans = len(lst)
print(ans)        