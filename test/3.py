import numpy as np
import sys

N, Q = map(int, input().split(" "))
s = input()
alpha = [chr(i) for i in range(65, 65+N)]
s_lst = np.array([alpha.index(i) for i in s])
gol = np.ones_like(s_lst)

for i in range(Q):
    t_str, d = input().split(" ")
    t = alpha.index(t_str)
    move_from = (s_lst == t)
    gol_move = gol * move_from
    gol[move_from] = 0
    if d == "R":
        gol_add = np.hstack((np.array([0]), gol_move[:-1]))
    else:
        gol_add = np.hstack((gol_move[1:], np.array([0])))
    gol = gol + gol_add
print(np.sum(gol))
sys.stdout.flush()