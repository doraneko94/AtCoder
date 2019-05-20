from collections import Counter
a = [1, 2, 3, 3]
b = [1]
print(sum((Counter(a) - Counter(b)).values()))
