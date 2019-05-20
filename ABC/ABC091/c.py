N = int(input())
ab = [[int(i) for i in input().split(" ")] for _ in range(N)]
cd = [[int(i) for i in input().split(" ")] for _ in range(N)]
ab_sort = sorted(ab, key=lambda x:-x[1])
cd_sort = sorted(cd, key=lambda x:x[0])

cnt = 0
for c, d in cd_sort:
    for a, b in ab_sort:
        if a < c and b < d:
            ab_sort.remove([a, b])
            cnt += 1
            break

print(cnt)