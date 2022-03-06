import heapq

def solution(food_times, k):
    answer = 0
    pq = []

    total = 0

    for i,f in enumerate(food_times):
        total += f
        heapq.heappush(pq, (f, i+1))

    if k >= total:
        return -1

    eat = 0

    while len(pq) > 0:
        l = len(pq)

        food = pq[0][0]

        if k > l * (food-eat):
            k -= l * (food-eat)
            eat = food
            heapq.heappop(pq)
        else:
            s = sorted(pq, key=lambda x: x[1])
            answer = s[k%l][1]
            break

    return answer



# print(solution([3,1,2],5), 1)
print(solution([1,1,1,1,1,1], 6), 6)
# print(solution([10,10,10,10,10,10], 100), -1)
# print(solution([10,10,2,10,10,10], 40), 5)
# print(solution([8,3,5], 3), 1)
# print(solution([4,2,3,6,7,1,5,8], 16), 3)
# print(solution([50000000,550000000,20000000,120000000,50000000,30000000,110000000000], 10000000000), 7)
# print(solution([100000,50000,1000], 50000), 1)
# print(solution([50000000,550000000,20000000,120000000,50000000,30000000,110000000000], 10000000000), 7)
# print(solution([100000,50000,1000], 50000), 1)
# print(solution([50000000,550000000,20000000,120000000,50000000,30000000,110000000000], 10000000000), 7)
# print(solution([110000000000,110000000000], 10000000000), 1)
