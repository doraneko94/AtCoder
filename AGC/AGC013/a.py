N = int(input())
A = [int(i) for i in input().split(" ")]

count = 1
key = 0
for i in range(N-1):
    if key == 0:
        if A[i+1] - A[i] > 0:
            key = 1
        elif A[i+1] - A[i] < 0:
            key = -1
        else:
            continue
    elif key == 1:
        if A[i+1] - A[i] < 0:
            key = 0
            count += 1
    else:
        if A[i+1] - A[i] > 0:
            key = 0
            count += 1
print(count)
