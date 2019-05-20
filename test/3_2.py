import numpy as np
import sys

N, Q = map(int, input().split(" "))
s = [np.nan] + list(input()) + [np.nan]
td = [input().split(" ") for _ in range(Q)]

l = 0
r = N+1

for i, j in td[::-1]:
    if s[l+1] == i and j == "L":
        l += 1
    elif s[l] == i and j == "R":
        l -= 1
    if s[r-1] == i and j == "R":
        r -= 1
    elif s[r] == i and j =="L":
        r += 1
ln = max(0, l)
rn = max(0, N+1-r)
print(N-ln-rn)