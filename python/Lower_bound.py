'''
이것이 취업을 위한 코딩테스트다 322p
'''

N, K = map(int, input().split())
ary = list(map(int, input().split()))


left, right = 0, len(ary) - 1

ans = N
while left <= right:
    mid = (left + right) // 2

    if ary[mid] >= K:
        ans = min(ans, mid)
        right = mid - 1
    else:
        left = mid + 1

print(ans + 1)




'''
5 7
1 3 5 7 7
------------
4
'''