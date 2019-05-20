X, Y, Z, K = list(map(int, input().split(" ")))
A = sorted(list(map(int, input().split(" "))), reverse=True)
B = sorted(list(map(int, input().split(" "))), reverse=True)
C = sorted(list(map(int, input().split(" "))), reverse=True)

import heapq

queue = [(-(A[0] + B[0] + C[0]), 0, 0, 0)]
heapq.heapify(queue)

visited = set()
for i in range(K):
    while True:
        v, a, b, c = heapq.heappop(queue)
        if (a, b, c) not in visited:
            break
    visited.add((a, b, c))
    print(-v)

    if a < X - 1:
        heapq.heappush(queue, (-(A[a + 1] + B[b] + C[c]), a + 1, b, c))
    if b < Y - 1:
        heapq.heappush(queue, (-(A[a] + B[b + 1] + C[c]), a, b + 1, c))
    if c < Z - 1:
        heapq.heappush(queue, (-(A[a] + B[b] + C[c + 1]), a, b, c + 1))
        