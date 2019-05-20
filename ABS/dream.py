S = input()
key = 0
while len(S) > 0:
    if S.startswith("dreamer"):
        S = S[7:]
        key = 1
    elif S.startswith("dream"):
        S = S[5:]
    elif S.startswith("eraser"):
        S = S[6:]
    elif S.startswith("erase"):
        S = S[5:]
    else:
        if key == 1:
            S = "er" + S
            key = 0
        else:
            print("NO")
            import sys
            sys.exit()

print("YES")