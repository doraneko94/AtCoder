import bisect

N = int(input())
wh = [[int(i) for i in input().split(" ")] for _ in range(N)]

wsort = sorted(wh, key=lambda x:(x[0], -x[1]))

wlst = [wsort[0][1]]

for _, h in wsort:
    if wlst[-1] < h:
        wlst.append(h)
    else:
        wlst[bisect.bisect_left(wlst, h)] = h

print(len(wlst))