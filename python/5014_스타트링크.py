'''
BOJ : https://www.acmicpc.net/problem/5014
'''

# 10 1 10 2 1
import collections

F, S, G, U, D = map(int,input().split())

q = collections.deque()
v = set()

q.append((S,0))
v.add(S)

solved = False

if S == G:
    print(0)
    exit()

while len(q) > 0:
    s, d = q.popleft()

    next_u = s + U
    next_d = s - D

    if next_u == G:
        solved = True
        print(d + 1)
        break
    elif next_d == G:
        solved = True
        print(d + 1)
        break

    if 1 <= next_u <= F and next_u not in v:
        q.append((next_u,d+1))
        v.add(next_u)
    if 1 <= next_d <= F and next_d not in v:
        q.append((next_d,d+1))
        v.add(next_d)

if not solved:
    print("use the stairs")