from collections import deque
N, M, K, X = map(int,input().split())

grp = {}
for i in range(M):
    fr, to = map(int,input().split())
    grp.setdefault(fr, [])
    grp[fr].append(to)


q = deque()

q.append((X,0))

dist = {}

visited = set()

while len(q) > 0:
    fr,d = q.popleft()

    visited.add(fr)
    if fr in grp:
        for to in grp[fr]:
            if to in visited:
                continue
            q.append((to, d + 1))
            visited.add(to)
            dist.setdefault(d + 1, [])
            dist[d+1].append(to)

if K not in dist:
    print(-1)
else:
    for i in sorted(dist[K]):
        print(i)
