'''
BOJ : https://www.acmicpc.net/problem/1339

O = IN
1 = OUT
'''
import collections
N = int(input())

words = []
num = 9

word_dict = {}
num_dict = {}
for i in range(N):
    words.append(input())

for word in words:
    for i,w in enumerate(reversed(word)):
        word_dict.setdefault(w, 0)
        num_dict.setdefault(i,[])
        word_dict[w] += i
        num_dict[i].append(w)

print(word_dict)
print(num_dict)

dic = {}

for d in range(10,0,-1):
    if d in num_dict:
        if len(num_dict[d]) > 1:
            pass

        else:
            w = num_dict[d][0]
            dic[w] = num
            num -= 1


print(dic)


