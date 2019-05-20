N = int(input())
A = []
for i in range(N):
    A.append(int(input()))
As = sorted(A)
num = 0
i = 0
while i < N:
    count = 0
    j = As[i]
    while i < N and As[i] == j:
        count += 1
        i += 1
    if count % 2 == 1:
        num += 1
print(num)