import numpy as np

c1 = [int(i) for i in input().split(" ")]
c2 = [int(i) for i in input().split(" ")]
c3 = [int(i) for i in input().split(" ")]
c = np.array([c1, c2, c3])

a = [[i[2] - i[1], i[1] - i[0]] for i in c.T]
b = [[i[2] - i[1], i[1] - i[0]] for i in c]

if a[0] == a[1] and a[2] == a[1] and b[0] == b[1] and b[1] == b[2]:
    print("Yes")
else:
    print("No")