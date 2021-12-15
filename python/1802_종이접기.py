'''
BOJ : https://www.acmicpc.net/problem/1802

O = IN
1 = OUT
'''
T = int(input())

for i in range(T):
    paper = list(input())


    answer = 'YES'

    while len(paper) > 1:

        mid = len(paper) // 2
        left = mid - 1
        right = mid + 1

        while right < len(paper):
            if paper[left] == paper[right]:
                answer = 'NO'
                break
            left -= 1
            right += 1

        paper = paper[:mid]

    print(answer)


'''
3
0
000
1000110
------------
YES
NO
YES
'''