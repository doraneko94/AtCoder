S = input()
T = input()
N = len(T)

if len(S) < N:
    print("UNRESTORABLE")
    import sys
    sys.exit()

flag = False
pos = 51
ans = ""
for i in range(len(S)-N+1):
    cnt = 0
    for j in range(N):
        if S[i+j] == "?" or S[i+j] == T[j]:
            cnt += 1
        else:
            break
    if cnt == N:
        pos = i
        flag = True
if flag:
    for i in range(len(S)):
        if pos <= i and i < pos + N:
            ans += T[i-pos]
        elif S[i] == "?":
            ans += "a"
        else:
            ans += S[i]
else:
    ans = "UNRESTORABLE"
print(ans)