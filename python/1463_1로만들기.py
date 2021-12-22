'''
BOJ : https://www.acmicpc.net/problem/1463
'''
N = int(input())

ary = [0]*1000001

ary[0] = 0
ary[1] = 0
ary[2] = 1
ary[3] = 1

for i in range(4,N+1):
    mn = 999999
    if i % 3 == 0:
        mn = min(ary[i//3] + 1, mn)
    if i % 2 == 0:
        mn = min(ary[i//2] + 1, mn)
    mn = min(ary[i-1] + 1, mn)
    ary[i] = mn

print(ary[N])
