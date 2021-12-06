def solution(N, M, K, ary):
    answer = 0
    sorted_ary = sorted(ary, reverse = True)

    print(sorted_ary)

    while True:
        if M > K:
            answer += sorted_ary[0] * K
            # print(answer)
            M -= K
        elif N < M:
            answer += sorted_ary[0] * K
            # print(answer)
            break
        answer += sorted_ary[1]
        # print(answer)
        M -= 1
        if M == 0:
            break


    return answer



print(solution(5,8,3,[2,4,5,4,6]), 46)