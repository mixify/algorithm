'''
https://programmers.co.kr/learn/courses/30/lessons/60057
'''


def solution(s):
    answer = 9999
    if (len(s) == 1):
        return 1
    for i in range(1, len(s) // 2 + 1):
        # print(str(i) ,' ======= ')
        perv = ''
        cnt = len(s)
        first = True
        '''
        for j in range(0,i):
            '''
        rep = 1
        res = ''
        for n in range(0, len(s) // i):
            splited = s[i * n: i * (n + 1)]
            # print(splited,perv,first,cnt)
            if (perv != ''):
                if (splited == perv):
                    rep = rep + 1
                    if (first):
                        cnt = cnt - i + 1
                        first = False
                    else:
                        cnt = cnt - i
                else:
                    res = res + str(rep) + perv
                    if (rep >= 1000):
                        cnt = cnt + 3
                    elif (rep >= 100):
                        cnt = cnt + 2
                    elif (rep >= 10):
                        cnt = cnt + 1

                    rep = 1
                    first = True

            perv = splited
        if (rep >= 1000):
            cnt = cnt + 3
        elif (rep >= 100):
            cnt = cnt + 2
        elif (rep >= 10):
            cnt = cnt + 1

        res = res + str(rep) + perv
        # print(perv)
        # print(str(i) + '=========')
        # print(res.replace('1',''), cnt)
        answer = min(cnt, answer)
    return answer

