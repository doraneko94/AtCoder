T = int(input())

for _ in range(T):
    S = input()
    flag = 0
    ans = 0
    for i, s in enumerate(S):
        if s == "o":
            flag += 1
            if flag == 2:
                if S[i-4:i+1] == "tokyo" or S[i-4:i+1] == "kyoto":
                    flag = 0
                    ans += 1
                else:
                    flag = 1
    print(ans)