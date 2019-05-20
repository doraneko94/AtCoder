N = int(input())
A = [int(i) for i in input().split(" ")]

cnt = 0
zero = False
for i in range(N):
    if A[i] < 0:
        cnt += 1
        A[i] *= -1
    elif A[i] == 0:
        zero = True
if cnt % 2 == 0 or zero:
        print(sum(A))
else:
    print(sum(A) - 2*min(A))