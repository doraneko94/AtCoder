a = [[1,2],[2,4],[4,3],[4,2],[3,1]]
print(sorted(a, key=lambda x: (x[0], -x[1])))