'''
https://codeup.kr/problem.php?id=5024
'''
N, C = map(int,input().split())
ary = []
for i in range(N):
    ary.append(int(input()))

ary.sort()
ans = 0
left, right = 0, ary[-1] - ary[0]

while left <= right:
    mid = (left + right) // 2

    perv = ary[0]

    cnt = 1

    for cow in ary[1:]:
        dis = cow - perv
        if dis <= mid:
            pass
        else:
            perv = cow
            cnt += 1
    
    if cnt >= C:
        ans = max(ans, mid)
        left = mid + 1
    else:
        right = mid - 1

print(ans + 1)