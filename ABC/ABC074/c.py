A, B, C, D, E, F = map(int, input().split(" "))

node = 0
aa = 0
bb = 0
cc = 0
dd = 0
na = int(F/(100*A))
nb = int(F/(100*B))
nc = int(F/C)
nd = int(F/D)
for a in range(na+1):
    for b in range(nb+1):
        for c in range(nc+1):
            for d in range(nd+1):
                if 100 * A * a + 100 * B * b + C * c + D * d > F or (A * a + B * b) * E < C * c + D * d:
                    break
                else:
                    if a == b == c == d == 0:
                        continue
                    else:
                        cand = (100 * (C * c + D * d)) / (100 * (A * a + B * b) + (C * c + D * d))
                        if cand > node:
                            node = cand
                            aa = a
                            bb = b
                            cc = c
                            dd = d
if node == 0:
    print("{} {}".format(100*A, 0))
else:
    print("{} {}".format(100*(A * aa + B * bb)+(C * cc + D * dd), C * cc + D * dd))