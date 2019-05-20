A, B = map(int, input().split(" "))
lst = sorted([A, B, A-1, B-1], reverse=True)
print(sum(lst[:2]))