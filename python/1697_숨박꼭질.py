import collections

N, K = map(int, input().split())

q = collections.deque()

v = set()

v.add(N)
q.append((N,0))


while len(q) > 0:
    pos, time = q.popleft()
    if pos == K:
        print(time)
        break

    p1, p2, p3 = pos - 1, pos + 1, pos * 2

    if 0 <= p1 <= 100000 and p1 not in v:
        v.add(p1)
        q.append((p1, time + 1))

    if 0 <= p2 <= 100000 and p2 not in v:
        v.add(p2)
        q.append((p2, time + 1))

    if 0 <= p3 <= 100000 and p3 not in v:
        v.add(p3)
        q.append((p3, time + 1))






'''
25 5 => 2
'''


