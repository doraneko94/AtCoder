import numpy as np
import sys
A, B, C = map(int, input().split(" "))
if A == B and B == C:
    sys.stdout.write("Yes")
    sys.stdout.flush()
else:
    sys.stdout.write("No")
    sys.stdout.flush()