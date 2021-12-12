'''
문자열 뒤집기 - 이것이 취업을 위한 코딩 테스트다 with 파이썬 313 P
https://www.acmicpc.net/problem/1439
'''

str = input()

cnt = 0

zero_group = 0
one_group = 0
# print(str.split('1'))
val = str[0]
for c in str[1:]:
    if c != val:
        if val == '0':
            zero_group += 1
        else:
            one_group += 1
    val = c

if val == '0':
    zero_group += 1
else:
    one_group += 1

# print(zero_group, one_group)
print(min(zero_group, one_group))




# print(val)

'''
0001100
-------------
1

010101
--------------
3

11111
--------------
0
'''
