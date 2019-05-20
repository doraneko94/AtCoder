import numpy as np
import math

N, K = map(int, input().split(" "))
As = map(int, input().split(" "))
if K == 0:
    print(sum([A for A in As]))
else:
    bit_lim = math.ceil(math.log2(K))
    A_array = np.array([[int(A / 2**i) % 2 for i in range(bit_lim)] for A in As])
    num1 = [np.count_nonzero(keta) for keta in A_array.T]
    ans = 0
    X = 0
    for i in range(bit_lim)[::-1]:
        if (num1[i] < (N / 2.0)) and (X + 2**i <= K):
            ans += (N - num1[i]) * 2**i
            X += 2**i
        else:
            ans += num1[i] * 2**i
    print(ans)