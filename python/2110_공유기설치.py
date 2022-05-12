'''
BOJ : https://www.acmicpc.net/problem/2110
'''

N, C = map(int, input().split())


house = []

for i in range(N):
    house.append(int(input()))

house.sort()

left = 1
right = house[N-1] - house[0]

answer = 0
while (left <= right):
    mid = (left + right) // 2

    cnt = 1

    prev = house[0]
    for i in range(1,N):
        dis = house[i] - prev
        if dis >= mid:
            cnt += 1
            prev = house[i]
    
    if cnt >= C:
        answer = max(answer, mid)
        left = mid + 1
    else:
        right = mid - 1

    
print(answer)



# print(house)
