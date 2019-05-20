N = int(input())
a = [int(i) for i in input().split(" ")]

lst = [0 for _ in range(max(a)+3)]
for x in a:
    lst[x] += 1
    lst[x+1] += 1
    lst[x+2] += 1
print(max(lst))
