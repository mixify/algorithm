'''
BOJ : https://www.acmicpc.net/problem/14503
'''
N, M = map(int, input().split())
r, c, d = map(int, input().split())

dy = [-1,0,1,0]
dx = [0,1,0,-1]

place = []
for i in range(N):
    place.append([])
    place[i] = list(map(int, input().split()))

clean_cnt = 0
rotate_cnt = 0

while True:

    if place[r][c] == 0:
        clean_cnt += 1

    place[r][c] = 2


    left = (d - 1) % 4
    left_r, left_c = r + dy[left], c + dx[left]


    #print(r, c)
    # for p in place:
    #     print(p)
    if place[left_r][left_c] == 0:
        d = left
        r, c = left_r, left_c
        rotate_cnt = 0
    else:
        d = left
        rotate_cnt += 1

        if rotate_cnt >= 4:
            back = (d + 2) % 4
            back_r, back_c = r + dy[back], c + dx[back]
            if place[back_r][back_c] == 1:
                break
            r, c = back_r, back_c
            rotate_cnt = 0


print(clean_cnt)
