S = [int(i) for i in input()]
s0 = [x for i,x in enumerate(S) if i % 2 == 0]
s1 = [x for i,x in enumerate(S) if i % 2 == 1]
# 0_1, 0_0, 1_1, 1_0
num01 = sum(s0)
num11 = sum(s1)
print(min(num01+len(s1)-num11, num11+len(s0)-num01))