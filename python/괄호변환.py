'''
https://programmers.co.kr/learn/courses/30/lessons/60058
'''

def legit(p):
    ret = ''
    stack = []
    legit = True
    for c in p:
        if c == '(':
            stack.append(c)
        else:
            if len(stack) > 0:
                stack.pop()
            else:
                legit = False
                break

    if len(stack) > 0:
        legit = False
    return legit

def fix(p):
    ret = ''

    word_cnt = {}

    word_cnt['('] = 0
    word_cnt[')'] = 0

    # print(p)

    for i, c in enumerate(p):
        word_cnt[c] += 1
        if word_cnt['('] == word_cnt[')']:
            u = p[:i+1]
            v = p[i+1:]

            if legit(u):
                ret = u + fix(v)
            else:
                ret = "(" + fix(v) + ")"


                u = u[1:-1]
                new_u = ''
                for uu in u:
                    if uu == "(":
                        new_u += ")"
                    else:
                        new_u += "("
                ret = ret + new_u
            break


    return ret


def solution(p):
    answer = ''
    if len(p) == 0:
        return p

    answer = fix(p)
    return answer


print(solution("(()())()"), "(()())()")
print(solution(")("), "()")
print(solution("()))((()"), "()(())()")
