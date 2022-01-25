'''
https://www.acmicpc.net/problem/1987

'''
R, C = map(int, input().split())

board = []
visit = [False] * 26
for i in range(R):
    board.append(input())
    # board.append([])
    # board[i] =''.join(input())

start_y, start_x = 0, 0

dy = [-1, 1, 0, 0]
dx = [0, 0, 1, -1]

def DFS(board, visit, y, x):
    ret = 1
    offset = ord('A')
    alpha = ord(board[y][x]) - offset
    visit[alpha] = True
    for d in range(4):
        next_y = y + dy[d]
        next_x = x + dx[d]
        if 0 <= next_y < R and 0 <= next_x < C :
            if not visit[ord(board[next_y][next_x]) - offset]:
                ret = max(ret, DFS(board, visit, next_y, next_x) + 1)
    visit[alpha] = False

    return ret


print(DFS(board, visit, 0, 0))