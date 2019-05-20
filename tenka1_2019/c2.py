import numpy as np
N = int(input())
S = input()
sa = np.array([1 if i == "#" else 0 for i in S])

c = 0
for i in range(N-1):
    if sa[i+1] != sa[i]:
        c += sum