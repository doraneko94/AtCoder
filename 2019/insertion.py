import numpy as np

def hantei(x):
    boo = [y in [j for j in range(1, i+2)] for i, y in enumerate(x)]
    return all(boo)

def proc(x, cand):
    if len(x) == 0:
        return cand
    else:
        x = np.array(x)
        add = np.linspace(0,len(x)-1,len(x))[[x[i] == i+1 for i in range(len(x))]][-1]
        cand.append(x[int(add)])
        return proc(a, cand)

a = "1 2 3 4 5"
a = [int(i) for i in a.split(" ")]
print(proc(a, []))

#if hantei(a):
