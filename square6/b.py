N = int(input())
A = []
B = []

for _ in range(N):
    a, b = map(int, input().split(" "))
    A.append(a)
    B.append(b)
As = sorted(A)
Bs = sorted(B)
en = As[int(len(A)/2)]
ex = Bs[int(len(B)/2)]
print(sum([abs(en-a) + abs(ex-b) + abs(a-b) for a,b in zip(A, B)]))
