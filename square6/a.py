from math import ceil

N, T = map(int, input().split(" "))
A = sum([a for a in map(int, input().split(" "))])
print(ceil(A/T))