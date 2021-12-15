'''
BOJ : https://www.acmicpc.net/problem/2138
힌트를 보고 풀었다
1. 버튼 2번 누르면 원복이니 그런 상황은 제외
2. 1번 스위치를 제외하고는 스위치를 누를때 스위치 왼쪽의 전구는 해당 스위치에 의해 마지막 값이 결정난다.
3. 그러므로 1번스위치를 누를때와, 누르지 않을때 두가지 케이스로 조사해서 하자
'''
import copy

N = int(input())
src = list(input())
dest = list(input())

answer = 0

# 1번 스위치 안 누름

src_no_press = copy.copy(src)

no_press_cnt = 0
for i in range(1, N):
    left = i - 1
    right = i + 2 if i + 1 < N else N
    if src_no_press[left] != dest[left]:
        no_press_cnt += 1
        for j in range(left, right):
            src_no_press[j] = '0' if src_no_press[j] == '1' else '1'

if src_no_press != dest:
    no_press_cnt = -1
# 1번 스위치 누름

src_press = copy.copy(src)
press_cnt = 1
src_press[0] = '0' if src_press[0] == '1' else '1'
src_press[1] = '0' if src_press[1] == '1' else '1'

for i in range(1, N):
    left = i - 1
    right = i + 2 if i + 1 < N else N
    if src_press[left] != dest[left]:
        press_cnt += 1
        for j in range(left, right):
            src_press[j] = '0' if src_press[j] == '1' else '1'

if src_press != dest:
    press_cnt = -1


if press_cnt == -1 and no_press_cnt == -1:
    print(-1)
else:
    print(min([v for v in [press_cnt, no_press_cnt] if v >= 0]))