'''
곱하기 혹은 더하기 - 이것이 취업을 위한 코딩 테스트다 with 파이썬 312 P
'''

str = input()


cnt = 0

val = int(str[0])
for c in str[1:]:
    # print(val)
    operand = int(c)
    # if val == 0 or operand <= 1: 둘다 1이하 일때 더하기가 무조건 유리
    if val <= 1 or operand <= 1:
        val = val + operand
    else:
        val = val * operand


print(val)

'''
02984
-------------
576

567
--------------
210
'''
