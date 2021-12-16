'''
BOJ : https://www.acmicpc.net/problem/2839
'''
N = int(input())

cm = 3 * 5

answer = -1

div = (N // cm) * 3 - 3
remain = N % cm + 15

if div < 0:
    div = 0
    remain -= 15

for i in range(10):
    for j in range(6):
        # print(i*3 + j*5)
        if i*3 + j*5 == remain:
            answer = min(n for n in [answer, div + i + j] if n > 0)

print(answer)
