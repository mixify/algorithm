'''
https://www.acmicpc.net/problem/19598
'''
import heapq

N = int(input())

answer = 0
meetings = []
for i in range(N):
    meetings.append(list(map(int, input().split())))


meetings.sort()

room_cnt = 0
ends = []
for m in meetings:
    start, end = m
    room_cnt += 1
    heapq.heappush(ends, end)
    while start >= ends[0]:
        heapq.heappop(ends)
        room_cnt -= 1

    answer = max(answer, room_cnt)



print(answer)



