N = int(input())
V = [int(i) for i in input().split(" ")]
C = [int(i) for i in input().split(" ")]

ans = 0
for v, c in zip(V,C):
    if v - c > 0:
        ans += v - c
print(ans)