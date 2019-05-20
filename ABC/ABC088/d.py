from collections import deque
import sys
sys.setrecursionlimit(10 ** 9)

H, W = map(int, input().split(" "))
S = [input() for _ in range(H)]

white = 0
black = 0
for i in range(H):
    for j in range(W):
        if S[i][j] == ".":
            white += 1
        else:
            black += 1
cnt = [[-1]*W for _ in range(H)]

def bfs():
    queue = deque([[0, 0]])
    cnt[0][0] = 0
    while queue:
        y, x = queue.popleft()
        for dy, dx in [[1,0], [-1,0], [0,1], [0,-1]]:
            if y+dy >= 0 and y+dy < H and x+dx >= 0 and x+dx < W:
                if cnt[y+dy][x+dx] == -1 and S[y+dy][x+dx] == ".":
                    cnt[y+dy][x+dx] = cnt[y][x] + 1
                    queue.append([y+dy,x+dx])

bfs()
if cnt[H-1][W-1] == -1:
    print("-1")
else:
    print(white-cnt[H-1][W-1]-1)