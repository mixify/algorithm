'''
BOJ : https://www.acmicpc.net/problem/1339

O = IN
1 = OUT
'''
import itertools
N = int(input())

words = []
num = 9

for i in range(N):
    words.append(input())

alphabets = set()
for word in words:
    for w in word:
        alphabets.add(w)

answer = 0
for perm in itertools.permutations(alphabets):
    dic = {}
    num = 9
    # for a in perm:
    #     dic[a] = str(num)
    #     num -= 1

    total = 0
    # for word in words:
    #     s = ''
    #     for alphabet in word:
    #         s += dic[alphabet]
    #     total += int(s)
    # answer = max(total,answer)

print(answer)


# print(total)
