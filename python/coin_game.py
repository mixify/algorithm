# d = {}
# def dp(a, b):
#     if (a,b) in d:
#         return d[(a,b)]
#
#     if a==b:
#         d[(a,b)] = 1
#         return d[(a,b)]
#     elif min(a,b) == 0:
#         d[(a,b)] = 1
#         return d[(a,b)]
import math


def solution(a, b):
    answer = [0,0]
    # [1,2],[5,3]를 만드는 님게임..
    if min(a,b) == 0 or a==b:
        answer = [0,1]
    else:
        if abs(a-b) == 1:
            answer = [0,3]

        # if (a+b) % 2 == 1:
        #     answer = [1,a+b-1]
        # else:
        #     answer = [0,a+b-1]
    return answer


print(solution(0,100), [0,1])
print(solution(1,2), [1,2])
