'''
BOJ : https://www.acmicpc.net/problem/14890
'''
N, L = map(int, input().split())

road = []

for i in range(N):
    road.append(list(map(int, input().split())))

cnt = 0
for i in range(N):
    valid = True
    visited = set()
    for j in range(1, N):
        prev = road[i][j-1]
        cur = road[i][j]

        if prev == cur:
            continue
        else:
            if abs(prev - cur) != 1:
                valid = False
                break
            if prev > cur:
                for k in range(j, j+L):
                    if k in visited:
                        valid = False
                        visited = set()
                        break

                    visited.add(k)

                    if k >= N:
                        valid = False
                        visited = set()
                        break
                    if road[i][k] != cur:
                        valid = False
                        visited = set()
                        break
            else:
                for k in range(j-1, j-L-1, -1):
                    if k in visited:
                        valid = False
                        visited = set()
                        break

                    visited.add(k)

                    if k < 0:
                        valid = False
                        visited = set()
                        break
                    if road[i][k] != prev:
                        valid = False
                        visited = set()
                        break
    if valid:
        # print('valid ', i)
        cnt += 1


for i in range(N):
    valid = True
    visited = set()
    for j in range(1, N):
        prev = road[j-1][i]
        cur = road[j][i]

        if prev == cur:
            continue
        else:
            # print(i,j,'-----------------')
            if abs(prev - cur) != 1:
                valid = False
                break
            if prev > cur:
                for k in range(j, j+L):
                    if k in visited:
                        valid = False
                        visited = set()
                        break

                    visited.add(k)

                    if k >= N:
                        valid = False
                        visited = set()
                        break
                    if road[k][i] != cur:
                        valid = False
                        visited = set()
                        break
            else:
                for k in range(j-1, j-L-1, -1):
                    if k in visited:
                        valid = False
                        visited = set()
                        break

                    visited.add(k)

                    if k < 0:
                        valid = False
                        visited = set()
                        break
                    if road[k][i] != prev:
                        valid = False
                        visited = set()
                        break
    if valid:
        # print('valid2 ', i)
        cnt += 1



print(cnt)

