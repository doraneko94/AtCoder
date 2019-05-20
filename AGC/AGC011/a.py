N, C, K = map(int, input().split(" "))
T = sorted([int(input()) for _ in range(N)])

bus = 0
i = 0
while i < N:
    bus += 1
    start = i
    while i < N and T[i] - T[start] <= K and i - start < C:
        i += 1
print(bus)
