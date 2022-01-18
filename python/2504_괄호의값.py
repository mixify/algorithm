'''
BOJ : https://www.acmicpc.net/problem/2504

‘()’ 인 괄호열의 값은 2이다.
‘[]’ 인 괄호열의 값은 3이다.
‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.

'''
s = input()

stack = []

total = 0
pre = 0
val = 0

def solve(s):
    if len(s) == 0:
        return 1

    ret = 0
    start = 0
    stack = []
    for i, c in enumerate(s):
        if c == '(' or c == '[':
            stack.append(c)
        else:
            if len(stack) == 0:
                return 0
            last = stack.pop()

            if last == '(' and c == ']':
                return 0
            if last == '[' and c == ')':
                return 0

            if len(stack) == 0:
                end = i
                if c == ')':
                    score =  2 * solve(s[start+1 : end])
                    if score == 0:
                        return 0
                    ret += score
                else:
                    score = 3 * solve(s[start+1 : end])
                    if score == 0:
                        return 0
                    ret += score
                start = i + 1

    if len(stack) > 0:
        return 0

    return ret


print(solve(s))




'''
(()[[]])([])
--------
28
'''
