'''
BOJ : https://www.acmicpc.net/problem/4963
'''
import collections

dy = [-1,-1,-1,1,1,1,0,0]
dx = [-1,0,1,-1,0,1,-1,1]

cnt_list = []
while True:
    w, h = map(int,input().split())

    if w+h == 0:
        break

    m = []
    visit = set()
    
    for i in range(h):
        m.append([])
        m[i] = list(map(int,input().split()))
    

    cnt = 0
    for i in range(h):
        for j in range(w):
            if m[i][j] == 1 and (i,j) not in visit:
                cnt += 1
                visit.add((i,j))
                q = [[i,j]]
                while len(q) > 0:
                    new_q = []
                    for y,x in q:
                        for d in range(8):
                            next_y = y + dy[d]
                            next_x = x + dx[d]
                            if 0 <= next_y < h and 0 <= next_x < w and (next_y,next_x) not in visit and m[next_y][next_x] == 1:
                                new_q.append([next_y,next_x])
                                visit.add((next_y,next_x))
                    q = new_q
    
    print(cnt)




    