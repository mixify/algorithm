'''
Programmers : https://programmers.co.kr/learn/courses/30/lessons/43236
'''

def solution(distance, rocks, n):
    answer = 0
    rocks.append(distance)
    rocks.sort()

    left = 1
    right = distance

    # 2 11 14 17 21

    while left <= right:
        mid = (left + right) // 2

        prev_rock = 0

        cnt = 0

        for rock in rocks:
            dis = rock - prev_rock
            if dis < mid:
                cnt += 1
            else:
                prev_rock = rock
            # else:

        
        if cnt <= n:
            answer = max(answer, mid)
            left = mid + 1
        else:
            right = mid - 1



            
    return answer

print(solution(25,[2, 14, 11, 21, 17], 2), 4)