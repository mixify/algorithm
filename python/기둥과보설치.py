'''
https://programmers.co.kr/learn/courses/30/lessons/60061

기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
'''
import copy

PILLAR = 0
BEAM = 1

DELETETION = 0
BUILD = 1


def validate(frames):
    frames = copy.deepcopy(frames)
    for b in frames:
        x, y, frame = b
        if frame == PILLAR:  # 기둥
            if y == 0:
                continue
            elif [x - 1, y, BEAM] in frames:
                continue
            elif [x, y, BEAM] in frames:
                continue
            elif [x, y - 1, PILLAR] in frames:
                continue
            else:
                return False
        else:  # 보
            if [x, y - 1, PILLAR] in frames:
                continue
            elif [x + 1, y - 1, PILLAR] in frames:
                continue
            elif [x - 1, y, BEAM] in frames and [x + 1, y, BEAM] in frames:
                continue
            else:
                return False
    return True

def solution(n, build_frame):
    answer = [[]]


    return_ary = []

    for b in build_frame:
        x, y, frame, operation = b
        if frame == PILLAR: # 기둥
            if operation == BUILD:
                if y == 0:
                    return_ary.append([x, y, frame])
                elif [x-1,y, BEAM] in return_ary:
                    return_ary.append([x, y, frame])
                elif [x, y, BEAM] in return_ary:
                    return_ary.append([x, y, frame])
                elif [x, y-1, PILLAR] in return_ary:
                    return_ary.append([x, y, frame])
            else:
                idx = return_ary.index([x, y, frame])
                # print(x,y,frame, return_ary)
                if validate(return_ary[:idx] + return_ary[idx+1:]):
                    del return_ary[idx]

        else: # 보
            if operation == BUILD:
                if [x, y-1, PILLAR] in return_ary:
                    return_ary.append([x, y, frame])
                elif [x+1,y-1, PILLAR] in return_ary:
                    return_ary.append([x, y, frame])
                elif [x-1, y, BEAM] in return_ary and [x+1, y, BEAM] in return_ary:
                    return_ary.append([x, y, frame])
            else:
                idx = return_ary.index([x, y, frame])
                # print(x,y,frame, return_ary)
                if validate(return_ary[:idx] + return_ary[idx + 1:]):
                    del return_ary[idx]

        # print(x,y,frame,operation)

    return_ary.sort()
    answer = return_ary
    return answer

print(solution(5, [[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]), [[1,0,0],[1,1,1],[2,1,0],[2,2,1],[3,2,1],[4,2,1],[5,0,0],[5,1,0]])
print(solution(5, [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]), [[0,0,0],[0,1,1],[1,1,1],[2,1,1],[3,1,1],[4,0,0]])
# print(solution(5, [[0,0,0,1],[2,0,0,1],[4,0,0,1],[0,1,1,1],[1,1,1,1],[2,1,1,1],[3,1,1,1],[2,0,0,0],[1,1,1,0],[2,2,0,1]]), [[0,0,0],[0,1,1],[1,1,1],[2,1,1],[3,1,1],[4,0,0]])
# print(solution(5, [[0,0,0,1], [0,1,1,1], [1,1,0,1], [2,0,0,1], [2,1,0,1], [2,1,0,0]]))
# print(solution(5, [[0,0,0,1], [3,0,0,1], [0,1,1,1], [2,1,1,1], [1,1,1,1], [2,1,0,1], [0,1,1,0], [3,0,0,0], [0,0,0,0],[1,1,1,0]]))
