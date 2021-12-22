def prime_list(n):
    ary = [True] * n

    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if ary[i] == True:
            for j in range(i + i, n, i):
                ary[j] = False
    return [i for i in range(2, n) if ary[i] == True]

def is_prime(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def solution(n):
    answer = [-1, -1]
    # root = int(1000000000000**0.5) + 1

    ary = prime_list(1000001)

    for p in ary:
        if n % p == 0:
            if is_prime(n//p):
                if p == n//p:
                    continue
                answer = [p, n // p]
                break

    return answer


print(solution(100000001))

