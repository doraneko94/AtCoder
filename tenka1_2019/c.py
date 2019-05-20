N = int(input())
S = input()

s = [0 for _ in range(N+1)]
for i, x in enumerate(S):
    if x == "#":
        s[i+1] = s[i] + 1
    else:
        s[i+1] = s[i]
num = N
for i in range(N+1):
    w = s[i] - s[0]
    b = (N - i) - (s[N] - s[i])
    if w + b < num:
        num = w + b
print(num)
