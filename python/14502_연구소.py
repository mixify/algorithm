import collections
import copy
from itertools import combinations
N, M = map(int, input().split())


m = []
for i in range(N):
    m.append([])
    m[i] = list(map(int, input().split()))

place_list = []
for i in range(N):
    for j in range(M):
        if m[i][j] == 0:
            place_list.append((i,j))

answer = 0

def diffusion(new_m, y, x):
    dq = collections.deque()
    visited = set()
    dy = [-1,1,0,0]
    dx = [0,0,1,-1]
    dq.append((y,x))
    visited.add((y,x))
    while len(dq) > 0:
        (y, x) = dq.popleft()
        for d in range(4):
            next_y = y + dy[d]
            next_x = x + dx[d]
            if 0 <= next_x < M and 0 <= next_y < N:
                if (next_y,next_x) not in visited and new_m[next_y][next_x] == 0:
                    visited.add((next_y, next_x))
                    dq.append((next_y,next_x))
                    new_m[next_y][next_x] = 2


def get_remain_place(new_m):
    cnt = 0
    for i in range(N):
        for j in range(M):
            if new_m[i][j] == 2:
                diffusion(new_m, i, j)
    for i in range(N):
        for j in range(M):
            if new_m[i][j] == 0:
                cnt += 1

    return cnt




for combs in combinations(place_list, 3):
    new_m = copy.deepcopy(m)
    for y,x in combs:
        new_m[y][x] = 1

    # for i in range(N):
    #     print(new_m[i])
    ret = get_remain_place(new_m)
    # print(ret)
    answer = max(answer, ret)
    # for i in range(N):
    #     print(new_m[i])
print(answer)





