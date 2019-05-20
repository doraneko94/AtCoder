N = int(input())
H = [int(i) for i in input().split(" ")]

cost = [0 for _ in range(N)]
for i in range(N-1):
    if i+1 == 1:
        cost[i+1] = abs(H[i+1] - H[i])
    else:
        cost[i+1] = min(abs(H[i+1] - H[i])+cost[i], abs(H[i+1] - H[i-1])+cost[i-1])
print(cost[-1])