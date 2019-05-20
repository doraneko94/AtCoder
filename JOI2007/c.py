import numpy as np
while True:
    N, M = map(int, input().split(" "))
    if N == M == 0:
        break
    P = np.sort([0]+[int(input()) for _ in range(N)])[::-1]
    s = 0
    for i in P[P<=M]:
        for j in P[P<=M+i]:
            for k in P[P<=M+i+j]:
                for l in P[P<=M+i+j+k]:
                    ans = i + j + k + l
                    if s < ans and M >= ans:
                        s = ans
    print(s)