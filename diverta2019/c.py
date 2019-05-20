N = int(input())

a = 0
b = 0
c = 0
ans = 0

for _ in range(N):
    s = input()
    flag = False
    for i in range(len(s)):
        if (flag == True) and (s[i] == "B"):
            ans += 1
            flag = False
        elif (s[i] == "A"):
            flag = True
        else:
            flag = False
    if (s[0] == "B" and s[-1] == "A"):
        c += 1
    elif (s[0] == "B"):
        b += 1
    elif (s[-1] == "A"):
        a += 1
if c > 0:
    ans += c - 1
    c = 1
    if (a > 0 or b > 0):
        ans += 1
print(ans + min(a, b))
