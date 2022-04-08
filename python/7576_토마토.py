'''
BOJ : https://www.acmicpc.net/problem/7576
'''

warehouse = []

day = 0

dy = [-1,1,0,0]
dx = [0,0,1,-1]

M, N = map(int, input().split())

for i in range(N):
    warehouse.append([])
    warehouse[i] = list(map(int,input().split()))

full = M*N
processed = 0

tomato_list = []


for i in range(N):
    for j in range(M):
        v = warehouse[i][j]

        if v == 1:
            tomato_list.append([i,j])
            processed += 1
        elif v == -1:
            full -= 1

answer = -1

while True:

    prev = processed
    # print('--------------')
    # for w in warehouse:
    #     print(w)

    new_tomato_list = []

    for tomato in tomato_list:
        y, x = tomato
        for d in range(4):
            next_y = y + dy[d]
            next_x = x + dx[d]
            
            if 0 <= next_y < N and 0 <= next_x < M and warehouse[next_y][next_x] == 0:
                warehouse[next_y][next_x] = 1
                new_tomato_list.append([next_y,next_x])
                processed += 1

    tomato_list = new_tomato_list
    if prev == processed:
        if processed == full:
            answer = day
        else:
            pass
        break

    day += 1
        
print(answer)




