'''
https://programmers.co.kr/learn/courses/30/lessons/42889?language=python3
'''

class level():
    def __init__(self, lvl):
        self.lvl = lvl
        self.cle= 0
        self.fail = 0
        self.fail_rate = 0
    
    def __repr__(self) -> str:
        return str(self.lvl) + " - " + str(self.cle) + "/" +  str(self.fail)

    def add_cle(self):
        self.cle += 1
    
    def add_fail(self):
        self.fail += 1
    
    def set_fail_rate(self):
        if (self.cle + self.fail) == 0:
            self.fail_rate = 0
        else:
            self.fail_rate = (self.fail) / (self.cle + self.fail)

    def __lt__(self, other):
        # total_self = self.cle + self.fail
        # if total_self == 0:
        #     self_fail_rate = 0
        # else:
        #     self_fail_rate = self.fail / total_self

        # total_other = other.cle + other.fail
        # if total_other == 0:
        #     other_fail_rate = 0
        # else: 
        #     other_fail_rate = other.fail / total_other

        return self.fail_rate > other.fail_rate

    def __eq__(self, other):
        return self.fail_rate == other.fail_rate
    
    def get_level(self):
        return self.lvl


def solution(N, stages):
    answer = []

    stg = []
    for i in range(N):
        stg.append(level(i+1))

    for s in stages:
        if s-1 < len(stg):
            stg[s-1].add_fail()
        for i in range(s-1):
            stg[i].add_cle()
            if i == len(stg) - 1:
                break
    
    for l in stg:
        l.set_fail_rate()

    for l in sorted(stg):
        answer.append(l.get_level())

    
    return answer



print(solution(5,[2, 1, 2, 6, 2, 4, 3, 3]),[3,4,2,1,5])
print(solution(4,[4,4,4,4,4]),[4,1,2,3])
# print(solution(100,[1,20,1,30,1]),[3])