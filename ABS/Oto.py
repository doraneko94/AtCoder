from itertools import permutations as pm
import sys

N, Y = map(int, input().split(" "))
sen = Y % 5000 / 1000
gosen = Y % 10000 / 5000 - sen
man = Y - sen * 1000 - gosen * 5000
if man != 0:
    for i in pm([1,2,6,10]):
        mai1 = N - sen - gosen
        mai2 = N - sen - gosen * 5
        s1 = 0
        g1 = 0
        m1 = 0
        s2 = 0
        g2 = 0
        m2 = 0
        man1 = 0
        man2 = 0
        for j in i:
            man1 += int(mai1/j) * 10000
            man2 += int(mai2/j) * 10000
            if j == 1:
                m1 += 1 * int(mai1/j)
                m2 += 1 * int(mai2/j)
            elif j == 2:
                g1 += 2 * int(mai1/j)
                g2 += 2 * int(mai2/j)
            elif j == 6:
                s1 += 5 * int(mai1/j)
                g1 += 1 * int(mai1/j)
                s2 += 5 * int(mai2/j)
                g2 += 1 * int(mai2/j)
            else:
                s1 += 10 * int(mai1/j)
                s2 += 10 * int(mai2/j)
            mai1 %= j
            mai2 %= j
        print(man1, man2)
        if man1 == man:
            print("{} {} {}".format(int(m1), int(g1+gosen), int(s1+sen)))
            sys.exit()
        elif man2 == man:
            print("{} {} {}".format(int(m2), int(g2), int(s2+sen+gosen*5)))
            sys.exit()
    
    print("-1 -1 -1")

else:
    print("0 {} {}".format(gosen, sen))