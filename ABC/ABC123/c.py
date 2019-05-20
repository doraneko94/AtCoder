from math import ceil
n = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

lst = [a, b, c, d, e]
v_min = min(lst)
time_slow = ceil(n/v_min)
print(4+time_slow)