'''
만들 수 없는 금액 - 이것이 취업을 위한 코딩 테스트다 with 파이썬 314 P
답지보고 풀었음
'''


N = int(input())
money = list(map(int, input().split()))

sorted_money = sorted(money)
# if sorted_money[0] > 1:
#     print(1)

target = 1
for v in sorted_money:

    # 꺼낸 동전이 target과 같을경우, 일치하는 존재하는 동전만으로 해당 금액을 만들 수 있꼬
    # 꺼낸 동전이 target보다 작을경우, 이전에 존재하는 동전으로 해당 금액을 만들 수 있다.
    if target < v:
        break
    target += v

# for i in range(1,100000):
#     print(i)

# for m in sorted_money:
#     print(m)

print(target)
# print(sorted_money)




'''
5
3 2 1 1 9
-------------
8

3
3 5 7
-------------
1

3
1 2 3
-------------
7

'''
