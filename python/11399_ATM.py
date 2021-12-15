'''
BOJ : https://www.acmicpc.net/problem/11399

O = IN
1 = OUT
'''
N = int(input())

people = list(map(int, input().split()))
people.sort()

answer = 0

time = 0
for i in people:
    time += i
    answer += time

print(answer)
'''
5
3 1 4 3 2
--------
32
'''
