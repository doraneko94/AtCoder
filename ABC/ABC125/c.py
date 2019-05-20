from math import gcd

N = int(input())
A = [int(i) for i in input().split(" ")]

if N == 2:
    print(max(A))
    import sys
    sys.exit()

g = gcd(A[0], A[1])
lmax = 1
num = 0
for i in range(2,N):
    cand = gcd(g, A[i])
    if cand < g:
        l = int(g / cand)
        g = cand
        if lmax < l:
            lmax = l
            num = A[i]
A = A[1:] + [A[0]]
g = gcd(A[0], A[1])
for i in range(2,N):
    cand = gcd(g, A[i])
    if cand < g:
        l = int(g / cand)
        g = cand
        if lmax < l:
            lmax = l
            num = A[i]
A = A[1:] + [A[0]]
g = gcd(A[0], A[1])
for i in range(2,N):
    cand = gcd(g, A[i])
    if cand < g:
        l = int(g / cand)
        g = cand
        if lmax < l:
            lmax = l
            num = A[i]
if num == A[0]:
    A = A[1:]
    flag = False
    N -= 1
elif num == A[1]:
    A = [A[0]] + A[2:]
    flag = False
    N -= 1
else:
    flag = True
g = gcd(A[0], A[1])
for i in range(2,N):
    if A[i] == num and flag:
        flag = False
    else:
        g = gcd(g, A[i])
print(g)