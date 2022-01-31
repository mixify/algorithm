'''
https://programmers.co.kr/learn/courses/30/lessons/60063
'''
import collections

def is_available(y1,x1,y2,x2,visited,N,board):
    if 0 <= y1 < N and 0 <= x1 < N and 0 <= y2 < N and 0 <= x2 < N:
        if board[y1][x1] == 0 and board[y2][x2] == 0:
            if ((y1, x1), (y2, x2)) not in visited:
                return True

    return False


def solution(board):
    answer = 9999

    q = collections.deque()

    q.append([(0,0),(0,1),0])

    N = len(board)

    v = set()
    v.add(((0,0),(0,1)))
    dy = [-1,1,0,0]
    dx = [0,0,1,-1]

    while len(q) > 0:
        r1,r2,dis = q.popleft()

        if r2[0] == N-1 and r2[1] == N-1:
            answer = min(answer, dis)

        for d in range(4):
            r1_next_y = r1[0] + dy[d]
            r1_next_x = r1[1] + dx[d]

            r2_next_y = r2[0] + dy[d]
            r2_next_x = r2[1] + dx[d]
            if is_available(r1_next_y, r1_next_x, r2_next_y, r2_next_x, v, N, board):
                v.add(((r1_next_y,r1_next_x),(r2_next_y,r2_next_x)))
                q.append([(r1_next_y,r1_next_x),(r2_next_y,r2_next_x), dis+1])

        if r1[0] == r2[0]: # horizontal
            if 0 <= r1[0] < N - 1 and board[r1[0] + 1][r1[1]] == 0 and board[r2[0] + 1][r2[1]] == 0:
                r1_next_y = r2[0]
                r1_next_x = r2[1]
                r2_next_y = r1[0] + 1
                r2_next_x = r2[1]

                if ((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)) not in v:
                    v.add(((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)))
                    q.append([(r1_next_y, r1_next_x), (r2_next_y, r2_next_x), dis + 1])

                r1_next_y = r1[0]
                r1_next_x = r1[1]
                r2_next_y = r1[0] + 1
                r2_next_x = r1[1]

                if ((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)) not in v:
                    v.add(((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)))
                    q.append([(r1_next_y, r1_next_x), (r2_next_y, r2_next_x), dis + 1])
            elif 0 < r1[0] < N and board[r1[0] - 1][r1[1]] == 0 and board[r2[0] - 1][r2[1]] == 0:
                r1_next_y = r1[0] - 1
                r1_next_x = r1[1]
                r2_next_y = r1[0]
                r2_next_x = r1[1]

                if ((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)) not in v:
                    v.add(((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)))
                    q.append([(r1_next_y, r1_next_x), (r2_next_y, r2_next_x), dis + 1])

                r1_next_y = r1[0] - 1
                r1_next_x = r2[1]
                r2_next_y = r2[0]
                r2_next_x = r2[1]

                if ((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)) not in v:
                    v.add(((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)))
                    q.append([(r1_next_y, r1_next_x), (r2_next_y, r2_next_x), dis + 1])

        else: # vertical
            if 0 <= r1[1] < N - 1 and board[r1[0]][r1[1] + 1] == 0 and board[r2[0]][r2[1] + 1] == 0:
                r1_next_y = r1[0]
                r1_next_x = r1[1]
                r2_next_y = r1[0]
                r2_next_x = r1[1] + 1

                if ((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)) not in v:
                    v.add(((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)))
                    q.append([(r1_next_y, r1_next_x), (r2_next_y, r2_next_x), dis + 1])

                r1_next_y = r2[0]
                r1_next_x = r2[1]
                r2_next_y = r2[0]
                r2_next_x = r2[1] + 1

                if ((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)) not in v:
                    v.add(((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)))
                    q.append([(r1_next_y, r1_next_x), (r2_next_y, r2_next_x), dis + 1])

            elif 0 < r1[1] < N and board[r1[0]][r1[1] - 1] == 0 and board[r2[0]][r2[1] - 1] == 0:

                r1_next_y = r1[0]
                r1_next_x = r1[1] - 1
                r2_next_y = r1[0]
                r2_next_x = r2[1]

                if ((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)) not in v:
                    v.add(((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)))
                    q.append([(r1_next_y, r1_next_x), (r2_next_y, r2_next_x), dis + 1])

                r1_next_y = r2[0]
                r1_next_x = r1[1] - 1
                r2_next_y = r2[0]
                r2_next_x = r1[1]

                if ((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)) not in v:
                    v.add(((r1_next_y, r1_next_x), (r2_next_y, r2_next_x)))
                    q.append([(r1_next_y, r1_next_x), (r2_next_y, r2_next_x), dis + 1])





    return answer


print(solution([[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]]), 7)
print(solution([[0, 0, 1, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0, 0, 0, 0], [1, 0, 0, 0, 1, 0, 0, 0, 0, 0], [1, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 1, 1, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 1, 1, 0, 1], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]), 18)
