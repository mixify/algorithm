'''
BOJ : https://www.acmicpc.net/problem/18310
'''


def get_dis(l, v):
    d = 0
    for h in l:
        d += abs(h-v)
    return d

N = int(input())
l = list(map(int,input().split()))

l.sort()

center = len(l) // 2
l_center = 0 if center == 0 else center - 1
r_center = len(l)-1 if center == len(l)-1 else center + 1

# print(get_dis(l, l[l_center]))
# print(get_dis(l, l[center]))
if get_dis(l, l[l_center]) <= get_dis(l, l[center]):
    print(l[l_center])
elif get_dis(l, l[r_center]) < get_dis(l, l[center]):
    print(l[r_center])
else:
    print(l[center])