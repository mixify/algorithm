'''
https://www.acmicpc.net/problem/14499
'''

N, M, y, x, K = map(int,input().split())

ary = []
cmd = []

dy = [0,0,0,-1,1]
dx = [0,1,-1,0,0]

dice = [[0 for _ in range(3)] for _ in range(4)]

for c in range(N):
    vals = list(map(int,input().split()))
    ary.append(vals)
cmd = list(map(int, input().split()))

for c in cmd:
    next_y = dy[c] + y
    next_x = dx[c] + x


    if 0 <= next_y < N and 0 <= next_x < M:
        row = dice[1] + [dice[3][1]]
        col = [d[1] for d in dice]

        # print(row)

        if c == 1:
            row = row[1:] + row[:1]
            dice[1] = row[:3]
            dice[3][1] = row[3]
        elif c == 2:
            row = row[3:] + row[:3]
            dice[1] = row[:3]
            dice[3][1] = row[3]
        elif c == 3:
            col = col[3:] + col[:3]
            for i in range(len(dice)):
                dice[i][1] = col[i]
        else:
            col = col[1:] + col[:1]
            for i in range(len(dice)):
                dice[i][1] = col[i]

        if ary[next_y][next_x] == 0:
            ary[next_y][next_x] = dice[1][1]
        else:
            dice[1][1] = ary[next_y][next_x]
            ary[next_y][next_x] = 0
        print(dice[3][1])
        # print(c,dice)
        # [print(a) for a in ary]
        y, x = next_y, next_x
