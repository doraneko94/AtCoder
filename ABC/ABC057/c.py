from math import sqrt

N = int(input())

F = 10**12
for i in range(int(sqrt(N))):
    if N % (i+1) == 0:
        cand = max([len(str(int(i+1))), len(str(int(N/(i+1))))])
        if F > cand:
            F = cand
print(cand)