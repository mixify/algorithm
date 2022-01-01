'''
BOJ : https://www.acmicpc.net/problem/3190
'''

N = int(input())
K = int(input())

dy = [0,1,0,-1]
dx = [1,0,-1,0]

apples = []
for i in range(K):
    y, x = map(int,input().split())
    apples.append([y,x])

L = int(input())

rotate = []
for i in range(L):
    t, d = input().split()
    t = int(t)
    rotate.append([t,d])

snake = [[1,1]]

direction = 0

t = 0
while True:
    t += 1

    y, x = snake[0][0], snake[0][1]
    moved_y, moved_x = y + dy[direction], x + dx[direction]

    if moved_y > N or moved_y < 1 or moved_x > N or moved_x < 1:
        print(t)
        break

    if [moved_y, moved_x] in snake:
        print(t)
        break

    if [moved_y, moved_x] in apples:
        apples.remove([moved_y,moved_x])
    else:
        del snake[-1]

    snake.insert(0,[moved_y,moved_x])

    if len(rotate) > 0:
        if rotate[0][0] == t:
            if rotate[0][1] == 'D':
                direction = (direction + 1) % 4
            else:
                direction = (direction - 1) % 4
            del rotate[0]

    # print(t, snake)

'''
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
'''
