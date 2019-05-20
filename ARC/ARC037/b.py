import sys
sys.setrecursionlimit(10**9)

N, M = map(int, input().split(" "))
edge = dict()
for _ in range(M):
    u, v = map(int, input().split(" "))
    if str(u) in edge:
        edge[str(u)].add(v)
    else:
        edge[str(u)] = set({v})
    if str(v) in edge:
        edge[str(v)].add(u)
    else:
        edge[str(v)] = set({u})

visited = set()

def dfs(x, x0=None):
    if {x}.issubset(visited):
        return False
    else:
        visited.add(x)
        time = 0
        same = 0
        if str(x) not in edge:
            return True
        for y in edge[str(x)]:
            if y != x0:
                if dfs(y, x) == True:
                    time += 1
            else:
                same += 1
        if time == len(edge[str(x)]) - same:
            return True
        else:
            return False

tree = 0
for i in range(N):
    if {i+1}.issubset(visited):
        pass
    else:
        if dfs(i+1) == True:
            tree += 1

print(tree)