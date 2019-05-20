n, m = map(int, input().split(" "))
a = list(map(int, input().split(" ")))

def turn(a0, a1, x, m):
    if a1 > a0:
        d1 = a1 - a0
    else:
        d1 = a1 - a0 + m
    if x > a0:
        d2 = x - a0
    else:
        d2 = x - a0 + m
    if d1 >= d2:
        return 1+d1-d2
    else:
        return d1 

print(min([sum([turn(a[i], a[i+1], x, m) for i in range(n-1)]) for x in range(1,m+1)]))