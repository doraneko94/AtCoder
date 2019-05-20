A, B, C, X, Y = map(int, input().split(" "))

a = 0
b = 0
c = 0

ABcand = min([X, Y])
if A + B >= C * 2:
    c += ABcand * 2
else:
    a += ABcand
    b += ABcand

if X == ABcand:
    res = Y - ABcand
    if B * res >= C * res * 2:
        c += res * 2
    else:
        b += res
else:
    res = X - ABcand
    if A * res >= C * res * 2:
        c += res * 2
    else:
        a += res
print(A*a+B*b+C*c)