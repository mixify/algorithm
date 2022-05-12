'''
https://codeup.kr/problem.php?id=4766
'''

N = int(input())
ary = list(map(int,input().split()))
M = int(input())

ans = 0
left, right = 0, M

while left <= right:
    mid = (left + right) // 2

    sum = 0
    for a in ary:
        sum += min(a, mid)

    if sum <= M:
        left = mid + 1
        ans = max(ans, mid)
    else:
        right = mid - 1

if ans > max(ary):
    print(max(ary))
else:
    print(ans)