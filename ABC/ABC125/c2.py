from math import gcd

N = int(input())
A = [int(i) for i in input().split(" ")]

left = [A[0]]
right = [A[-1]]

for i in range(N):
    left.append(gcd(left[i], A[i]))
    right.append(gcd(right[i], A[N-1-i]))

ans = 0
for i in range(N-1):
    gcd(left[i], right[])