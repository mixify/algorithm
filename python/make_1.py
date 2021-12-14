N, K = map(int, input().split())

answer = 0
while N > 1:
    if N % K == 0:
        N //= K
    else:
        N -= 1

    answer += 1


print(answer)



'''
25 5 => 2
'''


