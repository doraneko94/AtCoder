from collections import deque

R, C = map(int, input().split(" "))
sy, sx = map(int, input().split(" "))
gy, gx = map(int, input().split(" "))
c = [input() for _ in range(R)]
m = [[-1]*C for _ in range(R)]

def bfs():
    queue = deque([[sy-1, sx-1]])
    m[sy-1][sx-1] = 0
    while queue:
        y, x = queue.popleft()
        if [y, x] == [gy-1, gx-1]:
            return m[y][x]
        for dy, dx in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
            if y + dy >= 0 and y + dy < R and x + dx >= 0 and x + dx < C:
                if m[y+dy][x+dx] == -1 and c[y+dy][x+dx] == ".":
                    m[y+dy][x+dx] = m[y][x] + 1
                    queue.append([y+dy, x+dx])

print(bfs())