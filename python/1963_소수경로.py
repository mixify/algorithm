'''
BOJ : https://www.acmicpc.net/problem/1963
'''
import collections


def get_prime_list(n):
    ary = [True] * n
    
    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if ary[i] == True:
            for j in range(i + i, n, i):
                ary[j] = False
    return [i for i in range(2, n) if ary[i] == True]

def get_digit(number, n):
    return number // 10**n % 10

def get_reachable_prime_list(n, primes):
    reachable = []


    for d in range(0,4):
        digit = get_digit(n, d)
        fr = -digit
        to = 10 - digit
        for i in range(fr,to):
            next = n + i * (10**d)
            # print(i * (10**(d-1)))
            if next == n:
                continue
            if 1000 <= next < 10000 and next in primes:
                reachable.append(next)


    return reachable


N = int(input())

problems = []

for i in range(N):
    problems.append([])
    problems[i] = list(map(int, input().split()))

primes = get_prime_list(10000)

for p in problems:
    lis = []
    # q = collections.deque()

    lis.append([p[0], 0])
    visit = set()

    visit.add(p[0])

    possible = False
    while len(lis) > 0:
        new_lis = []
        for next, v in lis:
            if next == p[1]:
                possible = True
                print(v)

            pl = get_reachable_prime_list(next, primes)

            for reachable_prime in pl:
                if reachable_prime not in visit:
                    new_lis.append([reachable_prime, v+1])
                    visit.add(reachable_prime)
        
        lis = new_lis
            
    if not possible:
        print('impossible')
        