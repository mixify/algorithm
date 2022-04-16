'''
https://www.acmicpc.net/problem/1715
'''
import heapq

N = int(input())

# cards = []
heap = []
for i in range(N):
    heapq.heappush(heap, int(input()))

# for c in cards:
#     heapq.heappush(c)

total = 0
while len(heap) > 1:
    a,b = heapq.heappop(heap), heapq.heappop(heap)
    total += a + b
    heapq.heappush(heap, a+b)

print(total)

