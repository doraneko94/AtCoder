P = 10**9+7
B, W = map(int, input().split())

inv2 = [1]
fact = [1]
for i in range(B+W+10):
    inv2.append((inv2[-1] + (inv2[-1]%2) * P)//2)
    fact.append(fact[-1] * (i+1) % P)

def C(a, b):
    return fact[a]*pow(fact[b]*fact[a-b]%P, P-2, P) % P

L, R = 0, 0
for i in range(B+W):
    if i >= B:
        L *= 2
        L += C(i-1, B-1)
        L %= P
    if i >= W:
        R *= 2
        R += C(i-1, W-1)
        R %= P
    print(((R-L)*inv2[i+1]+inv2[1])%P)