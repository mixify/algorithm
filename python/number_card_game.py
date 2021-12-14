N, M = map(int, input().split())
card = []

answer = 0

for i in range(N):
    card.append(list(map(int, input().split())))

for row in card:
    answer = max(answer, min(row))

print(answer)



'''
3 3
3 1 2
4 1 4
2 2 2
'''


