'''
BOJ : https://www.acmicpc.net/problem/11047
'''

N, K = map(int, input().split())

coins = []
for i in range(N):
    coins.append(int(input()))

coins.sort(reverse=True)

for i, c in enumerate(coins):
    val = K
    answer = 0
    if c > K:
        continue
    else:
        cnt = val // c
        answer += cnt
        val -= c * cnt
        if val == 0:
            print(answer)
            exit()
        for cc in coins[i+1:]:
            if cc > val:
                continue
            else:
                cnt = val // cc
                val -= cc * cnt
                answer += cnt
                if val == 0:
                    print(answer)
                    exit()
