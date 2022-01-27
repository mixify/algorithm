'''
BOJ : https://www.acmicpc.net/problem/2146
'''
import collections

dy = [0,1,0,-1]
dx = [1,0,-1,0]

N = int(input())

m = []
visit = set()
for i in range(N):
    m.append([])
    m[i] = list(map(int, input().split()))

def BFS(m, visit, y, x):
    border_list = set()

    q = collections.deque()

    q.append((y,x))
    visit.add((y,x))

    while len(q) > 0:
        y,x = q.popleft()

        for d in range(4):
            next_y = y + dy[d]
            next_x = x + dx[d]
            if 0 <= next_y < N and 0 <= next_x < N and (next_y, next_x) not in visit:
                if m[next_y][next_x] == 0:
                    border_list.add((next_y, next_x))
                else:
                    q.append((next_y, next_x))
                    visit.add((next_y, next_x))

    return border_list



border_list = []
for i in range(N):
    for j in range(N):
        if m[i][j] == 1 and (i,j) not in visit:
            border_list.append(BFS(m, visit, i, j))

mm = 9999999
for i in range(len(border_list) - 1):
    for j in range(i+1, len(border_list)):
        bl1, bl2 = border_list[i], border_list[j]
        for y1, x1 in bl1:
            for y2, x2 in bl2:
                mm = min(abs(y1-y2) + abs(x1-x2), mm)

print(mm + 1)

