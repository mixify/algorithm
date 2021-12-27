'''
BOJ : https://www.acmicpc.net/problem/18406
'''
score = input()

half = len(score) // 2


left = sum([int(s) for s in score[:half]])
right = sum([int(s) for s in score[half:]])

if left == right:
    print('LUCKY')
else:
    print('READY')

'''
123402
7755
------------
LUCKY
READY
'''