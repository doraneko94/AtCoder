from math import ceil
a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
lst0 = [a%10, b%10, c%10, d%10, e%10]
lst = [(a-1)%10, (b-1)%10, (c-1)%10, (d-1)%10, (e-1)%10]
time0 = [int(a/10), int(b/10), int(c/10), int(d/10), int(e/10)]
time = [ceil(a/10), ceil(b/10), ceil(c/10), ceil(d/10), ceil(e/10)]
last = lst.index(min(lst))
time.pop(last)
print(sum(time)*10+lst0[last]+time0[last]*10)