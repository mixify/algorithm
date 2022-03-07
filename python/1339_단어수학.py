'''
BOJ : https://www.acmicpc.net/problem/1339

정답 참고해서 풀었음..
'''
import collections
N = int(input())

words = []
num = 9

for i in range(N):
    words.append(input())

alpha_dic = {}
for word in words:
    for i,w in enumerate(reversed(word)):
        alpha_dic.setdefault(w, 0)
        alpha_dic[w] += 10**i

alpha_list = []
for k, v in alpha_dic.items():
    alpha_list.append((v,k))

num_alpha_dic = {}
for _, a in sorted(alpha_list, reverse=True):
    num_alpha_dic[a] = num
    num -= 1


total = 0
for word in words:
    for alphabet, num in num_alpha_dic.items():
        word = word.replace(alphabet,str(num))
    total += int(word)


print(total)
