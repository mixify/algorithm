'''
BOJ : https://www.acmicpc.net/problem/2138
힌트를 보고 풀었다
1. 버튼 2번 누르면 원복이니 그런 상황은 제외
2. 1번 스위치를 제외하고는 스위치를 누를때 스위치 왼쪽의 전구는 해당 스위치에 의해 마지막 값이 결정난다.
3. 그러므로 1번스위치를 누를때와, 누르지 않을때 두가지 케이스로 조사해서 하자
'''

n, w, L = map(int, input().split())
trucks = list(map(int, input().split()))
go_trucks = []
out_time = []

t = 0
total_weight = 0

while len(trucks) > 0 or len(go_trucks) > 0:

    t += 1


    if t in out_time:
        passed = go_trucks[0]
        total_weight -= passed
        del go_trucks[0]

    if len(trucks) > 0:
        first = trucks[0]
        if total_weight + first <= L:
            go_trucks.append(first)
            total_weight += first
            out_time.append(t + w)
            del trucks[0]

    # print(t, trucks)
    # print(go_trucks, out_time)



print(t)

