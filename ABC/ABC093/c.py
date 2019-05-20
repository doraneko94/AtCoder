A, B, C = map(int, input().split(" "))

count = 0
oe = [A%2, B%2, C%2]

if sum(oe) == 2:
    count += 1
    if A%2 == 0:
        B += 1
        C += 1
    elif B%2 == 0:
        A += 1
        C += 1
    else:
        A += 1
        B += 1
elif sum(oe) == 1:
    count += 1
    if A%2 == 1:
        B += 1
        C += 1
    elif B%2 == 1:
        A += 1
        C += 1
    else:
        A += 1
        B += 1
lst = sorted([A, B, C])
count += int((lst[1] - lst[0]) / 2)
count += int(lst[2] - lst[1])
print(count)