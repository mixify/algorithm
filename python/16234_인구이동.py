'''
https://www.acmicpc.net/problem/16234
'''
from collections import deque

N, L, R = map(int,input().split())

countries = []
for i in range(N):
    countries.append([])
    countries[i] = list(map(int, input().split()))

groups = []

cnt = 0

def traverse(countries, i, j, visited):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, 1, -1]

    q = deque()
    q.append((i,j))

    group = []
    visited.add((i,j))
    group.append((i,j,countries[i][j]))
    while len(q) > 0:
        (y,x) = q.pop()


        for d in range(4):
            next_y = y + dy[d]
            next_x = x + dx[d]


            if 0 <= next_y < N and 0 <= next_x < N and (next_y, next_x) not in visited :
                dif = abs(countries[y][x] - countries[next_y][next_x])

                if L <= dif <= R:
                    q.append((next_y, next_x))
                    visited.add((next_y, next_x))
                    group.append((next_y, next_x,countries[next_y][next_x]))

    return group




cnt = 0
while True:
    visited = set()
    groups = []
    for i in range(N):
        for j in range(N):
            if (i,j) not in visited:
                groups.append(traverse(countries, i, j, visited))

    for group in groups:
        val = sum(g[2] for g in group) // len(group)
        for (i,j,_) in group:
            countries[i][j] = val

    if len(groups) == N*N:
        break

    cnt += 1


print(cnt)