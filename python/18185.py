N = int(input())
ary = list(map(int, input().split()))

answer = 0

for i in range(N):
    while True:
        three_sublist = ary[i:i+3]
        two_sublist = ary[i:i+2]
        three_adjacent = min(three_sublist)
        two_adjacent = min(two_sublist)
        if three_adjacent > 0 and len(three_sublist) == 3:
            answer += 7 * three_adjacent
            ary[i:i+3] = [x - three_adjacent for x in ary[i:i+3]]
        elif two_adjacent > 0 and len(two_sublist) == 2:
            answer += 5 * two_adjacent
            ary[i:i+2] = [x - two_adjacent for x in ary[i:i+2]]
        else:
            if ary[i] == 0:
                break
            else:
                answer += 3 * ary[i]
                ary[i] = 0


print(answer)



'''
3
1 0 1
------------
6

5
1 1 1 0 2
------------
12

3
2 1 2
------------
14
'''


