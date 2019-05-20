H, W = map(int, input().split(" "))
c = []
for i in range(H):
    inp = input()
    c.append(inp*(2*H-1))
fld = [[0 for _ in range(2*H-1)] for _ in range(H)]
fld[0][0] = 1
can = [dh*10+dw for dh, dw in [[1,0], [0,1]] if (dh<H and dw<W) and (c[dh][dw] == ".")]
while len(can) > 0:
    h = int(can[0]/10)
    w = int(can[0]%10)
    if h-1 >= 0 and c[h-1][w] == "." and fld[h-1][w] != 1:
        fld[h-1][w] = 1
        can.append((h-1)*10+w)
    if h+1 < H and c[h+1][w] == "." and fld[h+1][w] != 1:
        fld[h+1][w] = 1
        can.append((h+1)*10+w)
    if w-1 >= 0 and c[h][w-1] == "." and fld[h][w-1] != 1:
        fld[h][w-1] = 1
        can.append(h*10+(w-1))
    if w+1 < 2*H-1 and c[h][w+1] == "." and fld[h][w+1] != 1:
        fld[h][w+1] = 1
        can.append(h*10+(w+1))
    can = can[1:]
if fld[-1][-1] == 1:
    print("Yay!")
else:
    print(":(")