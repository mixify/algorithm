'''
https://www.acmicpc.net/problem/16235
'''
from queue import PriorityQueue

dy = [-1,1,0,0]
dx = [0,0,1,-1]
N, K = map(int, input().split())

m = []
for i in range(N):
    m.append([])
    m[i] = list(map(int, input().split()))


S, X, Y = map(int, input().split())

l = []

for i in range(N):
    for j in range(N):
        if m[i][j] != 0:
            l.append((m[i][j], (i,j)))


l.sort()

for t in range(S):
    if t > 282:
        break
    new_l = []
    for virus, (y,x) in l:
        for d in range(4):
            next_y = y + dy[d]
            next_x = x + dx[d]
            if 0 <= next_y < N and 0 <= next_x < N and m[next_y][next_x] == 0:
                m[next_y][next_x] = virus
                new_l.append((m[next_y][next_x], (next_y, next_x)))

    l = new_l


print(m[X-1][Y-1])