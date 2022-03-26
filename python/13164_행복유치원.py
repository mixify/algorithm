'''
https://www.acmicpc.net/problem/13164
5 3
5 2
5 1

1 3 5 6 10
 2 2 1 4
'''

N, K = map(int, input().split())
children = list(map(int, input().split()))

diffs = []
for i in range(len(children) - 1):
    diffs.append(children[i+1] - children[i])

diffs.sort()
# print(diffs)

answer = 0

i = 0
while N > K:
    answer += diffs[i]
    N -= 1
    i += 1

print(answer)

# if N == K:
#     print(0)
# else:


