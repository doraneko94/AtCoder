A = [input() for _ in range(10)]

import sys
sys.setrecursionlimit(10**9)

def dfs(y, x, first):
    if {(y,x)}.issubset(visited):
        return
    elif y < 0 or y >= 10 or x < 0 or x >= 10:
        return
    elif first == False and A[y][x] == "x":
        return
    else:
        if first == False:
            visited.add((y,x))
        dfs(y+1,x, False)
        dfs(y-1,x, False)
        dfs(y,x+1, False)
        dfs(y, x-1, False)
    return

O = set()
X = set()
for y, row in enumerate(A):
    for x, a in enumerate(row):
        if a == "o":
            O.add((y,x))
        else:
            X.add((y,x))
for y, x in X:
    visited = set()
    dfs(y, x, True)
    if O.issubset(visited):
        print("YES")
        sys.exit()
print("NO")
