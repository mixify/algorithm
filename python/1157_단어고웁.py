'''
https://www.acmicpc.net/problem/1157
'''



s = input()

s = s.lower()

d = {}
mx = 0
answer = 0
for c in s:
    d.setdefault(c,0)
    d[c] += 1
    if mx == d[c]:
        answer = '?'
    elif mx < d[c]:
        mx = max(mx, d[c])
        answer = c

print(answer.upper())







