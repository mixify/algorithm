'''
https://codeup.kr/problem.php?id=3002
'''


N = int(input())
digits = list(map(int, input().split()))
M = int(input())
nums = list(map(int, input().split()))

ans = []

for num in nums:
    left, right = 0, N - 1

    d = -1
    while left <= right:
        mid = (left + right) // 2

        if digits[mid] < num:
            left = mid + 1
        elif digits[mid] > num:
            right = mid - 1
        else:
            d = mid + 1
            break

    ans.append(d)

for a in ans:
    print(a, end=" ")


'''
5
2 23 55 87 100
4
5 2 100 55
------------
-1 1 5 3
'''