from collections import deque
import sys
sys.setrecursionlimit(10 ** 9)
H, W = map(int, input().split(" "))
c = [input() for _ in range(H)]
cnt = [[3]*W for _ in range(H)]
for i in range(H):
    for j in range(W):
        if c[i][j] == "s":
            sy = i
            sx = j
def bfs():
    queue = deque([[sy, sx]])
    cnt[sy][sx] = 0
    while queue:
        y, x = queue.popleft()
        for dy, dx in [[1,0], [-1,0], [0,1], [0,-1]]:
            if y+dy >= 0 and y+dy < H and x+dx >= 0 and x+dx < W:
                if cnt[y+dy][x+dx] != 3:
                    continue
                if c[y+dy][x+dx] == "g":
                    return "YES"
                if c[y+dy][x+dx] == "#":
                    if cnt[y][x] < 2:
                        queue.append([y+dy,x+dx])
                        cnt[y+dy][x+dx] = cnt[y][x] + 1
                else:
                    queue.appendleft([y+dy, x+dx])
                    cnt[y+dy][x+dx] = cnt[y][x]
    return "NO"
print(bfs())