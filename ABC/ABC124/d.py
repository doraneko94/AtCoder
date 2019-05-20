import numpy as np

N, K = map(int, input().split(" "))
S = np.array([int(i) for i in input()])
pos1 = np.linspace(0,N-1,N)[S == 1]
lst = []
if len(pos1) == 0:
    print(N)
else:    
    st =[pos1[0]]
    if len(pos1) != 1:
        for i in pos1[1:]:
            if st[-1] + 1 == i:
                st.append(i)
            else:
                lst.append(st)
                st = [i]
            if i == pos1[-1]:
                lst.append(st)
    else:
        lst.append(st)
    lst = [[0]] + lst + [[N-1]]
    time = len(lst) - K
    if time <= 0:
        print(N)
    else:
        print(int(max([max(lst[i+K]) - min(lst[i])+1 for i in range(time)])))