'''
https://programmers.co.kr/learn/courses/30/lessons/42885
'''



def solution(people, limit):
    answer = 0
    people.sort()
    i = 0
    j = len(people) - 1

    while i <= j:
        total_weight = people[i] + people[j]
        if total_weight <= limit:
            i += 1
            j -= 1
            answer += 1
        else:
            j -= 1
            answer += 1




    return answer

print(solution([70, 50, 80, 50], 100), 3)
print(solution([70,80,50], 100), 3)
