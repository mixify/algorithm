'''
https://www.acmicpc.net/problem/16235
'''
import collections

dy = [-1,1,0,0]
dx = [0,0,1,-1]

m = []
v = set()
cnt = 0

for i in range(7):
    m.append([])
    m[i] = list(map(int, input().split()))

def bfs(y,x):
    # print('bfs start ------',y,x)
    q = collections.deque()

    q.append((y,x))
    v.add((y,x))

    tiles = 1

    while len(q) > 0:
        y,x = q.popleft()
        # print(y,x)
        c = m[y][x]

        for d in range(4):
            next_y = y + dy[d]
            next_x = x + dx[d]

            if 0 <= next_y < 7 and 0 <= next_x < 7 and c == m[next_y][next_x] and (next_y,next_x) not in v:
                tiles += 1
                q.append((next_y,next_x))
                v.add((next_y,next_x))

    if tiles >= 3:
        return 1
    else:
        return 0


for i in range(7):
    for j in range(7):
        if (i,j) not in v:
            cnt += bfs(i,j)


print(cnt)