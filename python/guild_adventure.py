'''
모험가 길드 - 이것이 취업을 위한 코딩 테스트다 with 파이썬 311 P

처음에는 내림차순 정렬하여 모두 포함하려 했음

가장 많은 그룹수를 가지려면 어떻게 해야할지 먼저 생각해보자 반례도 생각해보고
'''

N = int(input())
member = list(map(int, input().split()))

sorted_member = sorted(member)

group_cnt = 0

cnt = 0
for i in range(len(sorted_member)):
    cnt += 1
    if cnt >= sorted_member[i]:
        group_cnt += 1
        cnt = 0


print(group_cnt)

'''
5
2 3 1 2 2
-------------
2

5
5 5 3 2 1 
--------------
1
'''
