'''
https://www.acmicpc.net/problem/16235
'''
from collections import deque

N, M, K = map(int, input().split())

dy = [-1,-1,-1,1,1,1,0,0]
dx = [1,0,-1,1,0,-1,-1,1]

ground_ary = []
nutrient_ary = []

ground_ary.append([-1])
nutrient_ary.append([-1])

for i in range(N):
    ground_ary.append([-1])
    nutrient_ary.append([-1])
    ground_ary[i+1] += [5] * N
    nutrient_ary[i+1] += list(map(int, input().split()))

tree_dict = {}

for i in range(M):
    y, x, z = map(int, input().split())
    tree_dict.setdefault((y,x), deque())
    tree_dict[(y,x)].append(z)

for (y, x) in tree_dict.keys():
    tree_dict[(y, x)] = deque(sorted(tree_dict[(y,x)]))

for k in range(K):
    # SPRING
    dead_dict = {}
    dead_list = deque()
    grow_list = deque()

    for (y,x) in tree_dict.keys():
        for i, t in enumerate(tree_dict[(y,x)]):
            if ground_ary[y][x] >= t:
                ground_ary[y][x] -= t

                tree_dict[(y,x)][i] = t + 1
                if (t + 1) % 5 == 0:
                    grow_list.append((y,x,t))
            else:
                dead_list.append((y,x,t))


    # SUMMER


    for (y,x,d) in dead_list:
        ground_ary[y][x] += d//2
        tree_dict[(y,x)].pop()


    # FALL
    for (y,x,d) in grow_list:
        for direction in range(len(dy)):
            next_y = y + dy[direction]
            next_x = x + dx[direction]
            if 0 < next_y <= N and 0 < next_x <= N:
                tree_dict.setdefault((next_y, next_x), deque())
                tree_dict[(next_y, next_x)].appendleft(1)


    # WINTER
    for i in range(1, N+1):
        for j in range(1, N+1):
            ground_ary[i][j] += nutrient_ary[i][j]
    # print(k)
    # print(ground_ary)
    # print(tree_dict)



answer = 0
for k,v in tree_dict.items():
    answer += len(v)

# print(tree_dict)
print(answer)




'''
5 3
1 3 2 3 2
-------------
8

8 5
1 5 4 3 2 4 5 2
-------------
25

'''
