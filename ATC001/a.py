H, W = map(int, input().split(" "))
c = []

for i in range(H):
    row = []
    for j,x in enumerate(input()):
        if x == "s":
            x0 = j
            y0 = i
        elif x == "g":
            x1 = j
            y1 = i
        row.append(x)
    c.append(row)

lst = []

def dfs(x, y):
    if x < 0 or x >= W or y < 0 or y >= H:
        return
    if (x, y) in lst:
        return
    if c[y][x] == "#":
        return
    elif c[y][x] == "g":
        lst.append((x, y))
        return
    else:
        lst.append((x, y))
        dfs(x+1, y)
        dfs(x-1, y)
        dfs(x, y+1)
        dfs(x, y-1)
    return

dfs(x0, y0)
if (x1, y1) in lst:
    print("Yes")
else:
    print("No")