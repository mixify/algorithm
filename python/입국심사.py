'''
Programmers : https://programmers.co.kr/learn/courses/30/lessons/43238
'''

def solution(n, times):
    right = answer = n * max(times)
    left = 1


    while left < right:
        total_time = 0
        mid = (left + right) // 2
        for time in times:
            total_time += mid // time
        print(left, right, total_time)

        if total_time >= n:
            right = mid
        else:
            left = mid + 1

    answer = left


    return answer