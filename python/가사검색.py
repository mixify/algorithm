'''
Programmers : https://programmers.co.kr/learn/courses/30/lessons/60060
'''

import sys

from openapi_schema_validator import oas30_format_checker
sys.setrecursionlimit(1000000)

class trie():

    def __init__(self):
        self.root = trieNode("")
    
    
    def insert_string(self, s):

        node = self.root
        for i in range(len(s)):
            c = s[i]
            

            n = node.cnt.get(len(s) - i, 0)
            node.cnt[len(s) - i] = n + 1

            if c in node.child:
                node = node.child[c]
            else:
                newNode = trieNode(c)
                node.child[c] = newNode
                node = newNode

          
    def query(self, node, q):
        cnt = 0
        for i in range(len(q)):
            c = q[i]
            if c != '?':
                if c in node.child:
                    node = node.child[c]
                else:
                    return cnt
            else:
                cnt += node.cnt.get(len(q) - i, 0)
                break
        
        return cnt





                # node.child[c] = trieNode()

class trieNode():

    def __init__(self, c):
        self.c = c
        self.cnt = {}
        self.child = {}


def solution(words, queries):
    answer = []
    count = {}
    t = trie()
    rev_t = trie()
    for w in words:
        cnt = count.get(len(w), 0)
        count[len(w)] = cnt + 1
        t.insert_string(w)
        w = w[::-1]
        rev_t.insert_string(w)

    for q in queries:
        if q[0] != '?':
            answer.append(t.query(t.root, q))
        else:
            q = q[::-1]
            answer.append(rev_t.query(rev_t.root, q))

    return answer


# print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],
#                ["fro???"]), [1])

print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],
               ["fro??", "????o", "fr???", "fro???", "pro?"]), [3, 2, 4, 1, 0])