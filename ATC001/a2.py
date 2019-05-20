H, W = map(int, input().split(" "))
C = [input() for _ in range(H)]

def find(s):
    for y, c in enumerate(C):
        for x, obj in enumerate(C[y]):
            if obj == s:
                return (y, x)

sy, sx = find("s")
gy, gx = find("g")

import sys
sys.setrecursionlimit(10**9)
visited = set()
def dfs(y, x):
    if {(y,x)}.issubset(visited):
        return False
    elif y > H-1 or y < 0 or x > W-1 or x < 0:
        return False
    elif C[y][x] == "#":
        return False
    elif y == gy and x == gx:
        return True
    else:
        visited.add((y,x))
        return dfs(y+1,x) or dfs(y-1,x) or dfs(y, x+1) or dfs(y, x-1)

print("Yes" if dfs(sy,sx) else "No")