N = int(input())
p = map(int, input().split(" "))

s = set({0})
for i in p:
    for j in list(s):
        s.add(j+i)
print(len(s))