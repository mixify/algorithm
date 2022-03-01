'''

https://www.acmicpc.net/problem/2193

'''
N = int(input())
d = [0] * 91

d[1] = 1
d[2] = 1
for i in range(3,N+1):
    d[i] = d[i-2] + d[i-1]

print(d[N])

# def DP(n):
#     if d[n] != 0:
#         return d[n]
#
#     if n == 1:
#         return 1
#
# print(DP(N))







