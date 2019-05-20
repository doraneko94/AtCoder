N = int(input())
s = list()
for _ in range(N):
    n = int(input())
    if len(s) == 0 or max(s) < n:
        s.append(n)
    else:
        for i in sorted(s):
            if i >= n:
                rem = i
                break
        s.append(n)
        s.remove(rem)
print(len(s))