ABCD = input()

for i in range(2 ** 3):
    ans = int(ABCD[0])
    pm = []
    for j in range(3):
        if (i >> j) & 1:
            ans += int(ABCD[j+1])
            pm.append("+")
        else:
            ans -= int(ABCD[j+1])
            pm.append("-")
    if ans == 7:
        print("{}{}{}{}{}{}{}=7".format(ABCD[0], pm[0], ABCD[1], pm[1], ABCD[2], pm[2], ABCD[3]))
        break