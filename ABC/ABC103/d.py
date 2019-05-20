import numpy as np
N, M = map(int, input().split(" "))
ab = np.array([[int(i) for i in input().split(" ")] for _ in range(M)])

ab_sort = ab[np.argsort(ab[:,1])]
ans = 0
nb = -1
for a, b in ab_sort:
    if a >= nb:
        ans += 1
        nb = b
print(ans)