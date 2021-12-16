'''
BOJ : https://www.acmicpc.net/problem/2839
'''
N = int(input())

cm = 3 * 5

answer = -1

# div = (N // cm) * 3
# remain = N % cm

# print(div, remain)
for i in range(2000):
    for j in range(1001):
        if i*3 + j*5 == N:
            answer = min(n for n in [answer, i + j] if n > 0)

# for i in range(2000):
#     for j in range(1000):
#         if i*3 + j*5 == remain:
#             answer = min(n for n in [answer, div + i + j] if n > 0)

print(answer)
