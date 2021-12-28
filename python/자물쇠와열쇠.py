'''
https://programmers.co.kr/learn/courses/30/lessons/60059
'''
import copy


def ins(key, lock, i, j):
    lock = copy.deepcopy(lock)
    # print(key, lock, i, j)
    for y in range(len(lock)):
        for x in range(len(lock)):
            if len(lock) > y + i >= 0 and len(lock) > x + j >= 0 and len(key) > y >= 0 and len(key) > x >= 0:
                lock[y+i][x+j] ^= key[y][x]
                if lock[y+i][x+j] == 0:
                    return False

    total = sum([sum(l) for l in lock])
    if total == len(lock)**2:
        return True
    # print(key, lock, i, j)
    # print('-------------------')

    return False


def solution(key, lock):
    fr = - len(key) + 1
    to = len(lock)
    for d in range(4):
        for i in range(fr, to):
            for j in range(fr, to):
                if ins(key[:], lock[:], i, j):
                    print(d,i,j)
                    return True
        key = list(zip(*key[::-1]))

    return False


# print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]), True)
# print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 0], [1, 1, 1, 1]]), True)
