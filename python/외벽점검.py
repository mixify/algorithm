'''
https://programmers.co.kr/learn/courses/30/lessons/60062

weak의 길이는 1 이상 15 이하입니다.
dist의 길이는 1 이상 8 이하입니다. // brute force

'''

import itertools

def get_within_areas(n, weak, dist, weak_outer_range):
    s = set()
    for w in weak_outer_range:
        if weak <= w <= weak + dist:
            s.add(w if w < n else w-n)
    return s




def solution(n, weak, dist):
    answer = -1

    weak_outer_range = weak + [e + n for e in weak]

    coverable = {}
    for d in dist:
        for w in weak:
            coverable[(d,w)] = get_within_areas(n, w, d, weak_outer_range)

    remaining_dists = dist[:]
    covered_weaks = set(weak)
    for i in range(1, len(dist) + 1):
        mx = 0
        mx_key = ()
        mx_val = set()

        for d in remaining_dists:
            for w in covered_weaks:
                if len(coverable[(d, w)]) > mx:
                    mx = len(coverable[(d, w)])
                    mx_key = [d,w]
                    mx_val = coverable[(d, w)]
        print(mx_key)
        remaining_dists.remove(mx_key[0])
        covered_weaks = covered_weaks.difference(mx_val)
        for k in coverable:
            coverable[k] = coverable[k].difference(mx_val)
        if len(covered_weaks) == 0:
            answer = i
            break





    if answer == 999999:
        answer = -1

    return answer

# print(solution(12, [1,5,6,10], [1,2,3,4]), 2)
# print(solution(12, [1,3,4,9,10], [3,5,7]), 1)
print(solution(50, [1,2,3,4,5,9,10,37], [3,20]), 2)
# print(solution(200, [10,20,30,40,50,60,70,80,90,100,110,120,130,140,150], [1,2,3,4,5,6,7,8]), -1)
# print(solution(121, [0,10,30,50,100,120], [5,10,50,100]), 1)
# print(solution(30, [1,3,4,9,10,15,20,23,24,25,26], [3,5,7,8,9,10,11,15]), 1)