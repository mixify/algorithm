'''
BOJ : https://www.acmicpc.net/problem/10825
'''

class st():
    def __init__(self, name, krs, ens, mas) -> None:
        self.name = name
        self.krs = krs
        self.ens = ens
        self.mas = mas
    
    def __repr__(self) -> str:
        return str(self.name) + " : " + str(self.krs) +\
            " : " + str(self.ens) + " : " + str(self.mas)


    def __lt__(self, other):
        if self.krs == other.krs:
            if self.ens == other.ens:
                if self.mas == other.mas:
                    return self.name < other.name 
                return self.mas > other.mas
            return self.ens < other.ens
        return self.krs > other.krs
    
    def __eq__(self, other):
        return self.name == other.name and self.krs == other.krs and \
            self.ens == other.ens and self.mas == other.mas
    def getName(self):
        return self.name

N = int(input())

stl = []

for i in range(N):
    name, krs, ens, mas = input().split()
    stl.append(st(name,int(krs),int(ens),int(mas)))

# print(stl[9])
# print(stl[8])
# print(stl[9] > stl[8])

for s in sorted(stl):
    # print(s)
    print(s.getName())
