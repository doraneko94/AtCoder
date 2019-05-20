import numpy as np

N = int(input())
t = np.zeros(N+1)
x = np.zeros(N+1)
y = np.zeros(N+1)
for i in range(N):
    t[i+1], x[i+1], y[i+1] = map(int, input().split(" "))
dx = x[1:] - x[:-1]
dy = y[1:] - y[:-1]
dt = t[1:] - t[:-1]
dxdy = np.abs(dx) + np.abs(dy)
if np.sum((dt >= dxdy) & ((dt-dxdy)%2==0)) != dxdy.shape[0]:
    print("No")
else:
    print("Yes")