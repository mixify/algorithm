'''
https://programmers.co.kr/learn/courses/30/lessons/42885
'''
import copy
from itertools import combinations

N = int(input())

room = []
for i in range(N):
    room.append([])
    room[i] = list(input().split())

teacher_list = []
empty_list = []
for i in range(N):
    for j in range(N):
        if room[i][j] == 'X':
            empty_list.append((i,j))
        elif room[i][j] == 'T':
            teacher_list.append((i,j))

def check(room, y, x):
    dy = [-1,1,0,0]
    dx = [0,0,1,-1]
    for d in range(4):
        next_y = y
        next_x = x
        while 0 <= next_y < N and 0 <= next_x < N:
            if room[next_y][next_x] == 'O':
                break
            elif room[next_y][next_x] == 'S':
                return False
            next_y += dy[d]
            next_x += dx[d]

    return True

for comb in combinations(empty_list,3):
    temp_room = copy.deepcopy(room)

    for (y,x) in comb:
        temp_room[y][x] = 'O'

    okay = True
    for (teacher_y, teacher_x) in teacher_list:
        if check(temp_room, teacher_y, teacher_x) == False:
            okay = False
            break
    if okay:
        print('YES')
        exit()

print('NO')



