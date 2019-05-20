nedan = int(input())
otsuri = 1000 - nedan
coin = [500, 100, 50, 10, 5, 1]
ans = 0
for c in coin:
    ans += int(otsuri/c)
    otsuri %= c
print(ans)