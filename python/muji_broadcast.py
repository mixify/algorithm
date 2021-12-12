'''
무지의 먹방 라이브 - https://programmers.co.kr/learn/courses/30/lessons/42891

효율성테스트 1개밖에 성공못함
'''


def solution(food_times, k):
    answer = 0


    while True:
        available_foods = [f for f in food_times if f > 0]
        if len(available_foods) == 0:
            return -1
        # print(available_foods)
        ll = len(available_foods)
        mm = min(available_foods)

        if k > ll:
            if k > ll*mm:
                k -= ll*mm
                food_times = [f - mm for f in food_times]
            else:
                i = mm
                while True:
                    if k > ll*i:
                        k -= ll * i
                        food_times = [f - i for f in food_times]
                        break
                    i = i//2
            # else:
            #     k -= ll
            #     food_times = [f - 1 for f in food_times]
        else:
            for i, f in enumerate(food_times):
                if f > 0:
                    if k == 0:
                        return i + 1
                    food_times[i] -= 1
                    k -= 1

    # print(food)
    # print(food_times.index(food))
    # answer = food_times.index(food) + 1



    return answer


print(solution([3,1,2], 5), 1)
print(solution([1,1,1,1,1,1], 5), 6)
print(solution([10,10,10,10,10,10], 100), -1)
print(solution([3,3,3], 7), 2)
print(solution([100000,100000], 10), 1)
print(solution([50000000,550000000,20000000,120000000,50000000,30000000,110000000000], 10000000000), 7)
print(solution([110000000000,110000000000], 10000000000), 1)
