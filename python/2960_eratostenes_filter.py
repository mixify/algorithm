'''
BOJ : https://www.acmicpc.net/problem/2960
'''

N, K = map(int, input().split())

prime_ary = [0] * (N + 1)
prime_ary[0] = 1

cnt = 0

for i in range(2, N+1):
    for j in range(i, N+1, i):
        # print(j, cnt)
        if prime_ary[j] == 0:
            cnt += 1
            prime_ary[j] = 1
            if cnt == K:
                print(j)
                exit(0)