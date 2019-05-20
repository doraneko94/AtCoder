S = input()
maxlen = 0
l = 0
for s in S:
    if s in ["A", "T", "G", "C"]:
        l += 1
    else:
        if l > maxlen:
            maxlen = l
            l = 0
if l > maxlen:
    maxlen = l
print(maxlen)