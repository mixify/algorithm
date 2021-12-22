def prime_list(n):
    ary = [True] * n

    m = int(n ** 0.5)
    for i in range(2, m + 1):
        if ary[i] == True:
            for j in range(i + i, n, i):
                ary[j] = False
    return [i for i in range(2, n) if ary[i] == True]


def solution(N, M):
    answer = 0
    prime_ary = prime_list(N)
    sum_ary = [0] * (len(prime_ary) + 1)

    sum_ary[0] = 0
    for i in range(len(prime_ary)):
        sum_ary[i+1] = sum_ary[i] + prime_ary[i]
    # prime_ary = prime_list(3000000)
    # print(len(prime_ary))

    # print(prime_ary)
    # print(sum_ary)
    threshold = 0


    # print(prime_ary)

    start = 0
    end = 0

    # print(prime_ary)
    while start <= end and end <= len(prime_ary):
        # print(prime_ary[start:end+1], sum_ary[end], sum_ary[start])
        val = sum_ary[end] - sum_ary[start]
        # print(val)
        if val < M:
            end += 1
        elif val > M:
            start += 1
        else:
            answer += 1
            start += 1



    return answer


# print(solution(12, 10), 1)
# print(solution(20, 36), 2)
# print(solution(100, 83), 3)
