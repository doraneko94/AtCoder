N = int(input())
hat = input()
r = 0
for i in hat:
    if i == "R":
        r += 1
if r > N/2:
    print("Yes")
else:
    print("No")