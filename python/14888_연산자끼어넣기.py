'''
https://www.acmicpc.net/problem/14888
'''
from itertools import permutations
N = int(input())
digit_list = list(map(int, input().split()))

p, m, mp, div= map(int, input().split())

oper_list = []
for i in range(p):
    oper_list.append('+')
for i in range(m):
    oper_list.append('-')
for i in range(mp):
    oper_list.append('*')
for i in range(div):
    oper_list.append('/')

mx = -1000000000
mn = 1000000000
for comb in permutations(oper_list, N - 1):
    res = digit_list[0]
    for i in range(len(comb)):
        op = comb[i]

        if op == '+':
            res += digit_list[i + 1]
        elif op == '-':
            res -= digit_list[i + 1]
        elif op == '*':
            res *= digit_list[i + 1]
        elif op == '/':
            if res < 0:
                res = -res
                res //= digit_list[i + 1]
                res = -res
            else:
                res //= digit_list[i + 1]

    mx = max(mx, res)
    mn = min(mn, res)



print(mx)
print(mn)

'''
10
1 2 3 4 5 6 7 8 9 10
2 3 2 2

11
1 2 3 4 5 6 7 8 9 10 11
2 3 2 3
'''