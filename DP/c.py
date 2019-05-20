N = int(input())
a = [0 for _ in range(N)]
b = [0 for _ in range(N)]
c = [0 for _ in range(N)]

for i in range(N):
    a[i], b[i], c[i] = map(int, input().split(" "))
happy = [[0 for _ in range(3)] for _ in range(N)]
for i in range(N):
    if i == 0:
        happy[i][0] = a[i]
        happy[i][1] = b[i]
        happy[i][2] = c[i]
    else:
        happy[i][0] = max(happy[i-1][1]+a[i], happy[i-1][2]+a[i])
        happy[i][1] = max(happy[i-1][0]+b[i], happy[i-1][2]+b[i])
        happy[i][2] = max(happy[i-1][0]+c[i], happy[i-1][1]+c[i])
print(max(happy[-1]))