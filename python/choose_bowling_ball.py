'''
볼링공 고르기 - 이것이 취업을 위한 코딩 테스트다 with 파이썬 315 P
'''

import collections

N, K = map(int, input().split())
balls = list(map(int, input().split()))

counter = collections.Counter(balls)

keys = list(counter.keys())

answer = 0

for i in range(len(keys)):
    v = counter[keys[i]]
    for j in range(i+1, len(keys)):
        w = counter[keys[j]]
        answer += v*w


print(answer)

# for key in counter.keys():
#     print(key)
# for k,v in collections.Counter(balls):
#     print(k,v)





'''
5 3
1 3 2 3 2
-------------
8

8 5
1 5 4 3 2 4 5 2
-------------
25

'''
