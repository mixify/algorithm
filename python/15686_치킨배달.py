'''
https://www.acmicpc.net/problem/15686

기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
'''
import itertools

N, M = map(int, input().split())

house = []
chicken = []
for i in range(N):
    input_list = list(map(int, input().split()))
    for j,v in enumerate(input_list):
        if v == 1:
            house.append([i,j])
        elif v == 2:
            chicken.append([i,j])


min_sum = 9999999
for comb in list(itertools.combinations(chicken,M)):
    total = 0
    for h in house:
        min_dis = 999999
        for c in comb:
            min_dis = min(abs(h[0] - c[0]) + abs(h[1] - c[1]), min_dis)
        total += min_dis
    min_sum = min(min_sum, total)

print(min_sum)



