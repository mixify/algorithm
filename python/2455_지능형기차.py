'''
BOJ : https://www.acmicpc.net/problem/2455
'''

answer = 0
human = 0
info = []
for i in range(4):
    down, up = map(int, input().split())
    human -= down
    human += up
    answer = max(answer,human)

print(answer)






