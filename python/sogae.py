def solution(C, F, X):
    answer = 9999999.999999

    perv = C / 2

    part_time_chicken = 0

    answer = X / 2

    # for i in range(100000):
    for i in range(200):
        part_time_chicken += C / (2+i*F)
        # for j in range(i):
            # perv += C / (2.0 + j*F)
        efficiency = F*(i+1) + 2.0
        t = part_time_chicken + X / efficiency
        print(t)
        answer = min(t, answer)

    return round(answer,6)


# print(solution(30.0, 1.0, 2.0), 1.0)
# print(solution(30.0, 2.0, 100.0), 39.166667)
print(solution(30.5, 3.14159, 1999.1999), 63.968001)
# print(solution(500.0, 4.0, 2000.0), 526.190476)
