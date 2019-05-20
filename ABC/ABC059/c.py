n = int(input())
a = [int(i) for i in input().split(" ")]

s = 0
num1 = 0
for i, x in enumerate(a):
    if i == 0:
        if x > 0:
            s = x
        else:
            s = 1
            num1 += abs(1-x)
    else:
        if s > 0:
            if s + x < 0:
                s += x
            else:
                num1 += abs(-s-x-1)
                s = -1
        else:
            if s + x > 0:
                s += x
            else:
                num1 += abs(-s-x+1)
                s = 1
s = 0
num2 = 0
for i, x in enumerate(a):
    if i == 0:
        if x < 0:
            s = x
        else:
            s = -1
            num2 += abs(-1-x)
    else:
        if s > 0:
            if s + x < 0:
                s += x
            else:
                num2 += abs(-s-x-1)
                s = -1
        else:
            if s + x > 0:
                s += x
            else:
                num2 += abs(-s-x+1)
                s = 1
print(min([num1, num2]))