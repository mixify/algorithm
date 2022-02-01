'''
H = 3 W = 4
'''
import collections

K = int(input())


for t in range(K):
    V, E = map(int, input().split())
    graph = {}
    for i in range(E):
        fr, to = map(int, input().split())
        graph.setdefault(fr, [])
        graph.setdefault(to, [])
        graph[fr].append(to)
        graph[to].append(fr)

    visit = [2] * 20001

    legit = True

    q = collections.deque()

    for v in graph.keys():
        if visit[v] == 2:
            q.append((v,1))
            visit[v] = 1


        while len(q) > 0:
            n, c = q.popleft()

            for to in graph[n]:
                if visit[to] == 2:
                    q.append((to, c^1))
                    visit[to] = c^1
                else:
                    if visit[to] == c:
                        legit = False
                        break

            if not legit:
                break

    if legit:
        print('YES')
    else:
        print('NO')

