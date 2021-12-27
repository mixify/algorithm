'''
이것이 취업을 위한 코딩테스트다 322p
'''
s = input()


print(''.join(sorted([c for c in s if 'A' <= c <= 'Z'])) + str(sum([int(i) for i in s if '0' <= i <= '9'])))

'''
123402
7755
------------
LUCKY
READY
'''