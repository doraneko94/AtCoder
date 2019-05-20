A, B, C = map(int, input().split(" "))
if A < C:
    if B > C:
        print("Yes")
    else:
        print("No")
else:
    if B < C:
        print("Yes")
    else:
        print("No")
