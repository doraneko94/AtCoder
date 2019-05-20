from collections import Counter
N, K = map(int, input().split(" "))
s_list = list(input())
s_sorted = sorted(s_list)
t = ""

diff = 0
for i in range(N):
    c = Counter(s_list[:i+1]) - Counter(t)
    for s in s_sorted:
        diff1 = diff + (s != s_list[i])
        diff2 = sum(c.values()) - (c[s]>0)
        if diff1+diff2 <= K:
            t += s
            s_sorted.remove(s)
            diff = diff1
            break
print(t)