'''
H = 3 W = 4
'''
def validate_1(y, x, W, H, room):
    for i in range(y, y+H):
        if room[i][x] == 0:
            return 0
        if room[i][x+W-1] == 0:
            return 0
    for j in range(x, x+W):
        if room[y][j] == 0:
            return 0

    return 1

def validate_2(y, x, W, H, room):
    for i in range(y, y+H):
        if room[i][x] == 0:
            return 0
        if room[i][x+W-1] == 0:
            return 0
    for j in range(x, x+W):
        if room[y + H - 1][j] == 0:
            return 0

    return 1

def validate_3(y, x, W, H, room):
    for j in range(x, x+H):
        if room[y][j] == 0:
            return 0
        if room[y+W-1][j] == 0:
            return 0
    for i in range(y, y+W):
        if room[i][x] == 0:
            return 0

    return 1

def validate_4(y, x, W, H, room):
    for j in range(x, x+H):
        if room[y][j] == 0:
            return 0
        if room[y+W-1][j] == 0:
            return 0
    for i in range(y, y+W):
        if room[i][x+H-1] == 0:
            return 0

    return 1


def solution(isAvailable, N, M, H, W):
    #
    answer = 0

    room = []

    for i in range(N):
        room.append([])
        for c in isAvailable[i]:
            room[i].append(int(c))

    # for row in room:
    #     print(row)
    #
    # print('------------')
    y, x = 0, 0

    for y in range(N - H + 1):
        for x in range(M - W + 1):
            answer += validate_1(y,x,W,H,room)
            answer += validate_2(y,x,W,H,room)


    for y in range(N - W + 1):
        for x in range(M - H + 1):
            answer += validate_3(y,x,W,H,room)
            answer += validate_4(y,x,W,H,room)








    return answer

print(solution(["1111", "1011", "1011", "1111"], 4, 4, 2, 3), 6)
print(solution(["111110", "110110", "110110", "111110", "111110"], 5, 6, 3, 4), 10)
