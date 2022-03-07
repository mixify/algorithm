'''
https://programmers.co.kr/learn/courses/30/lessons/42860


BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
ABBBAAAAAABA
AAABAAAAA
AAABAAAAAAAAAABB

ABCDEFGHIJKLMNOPQRSTUVWXYZ
'''

def get_letter_close(word):
    if ord(word) < ord('N'):
        return ord(word) - ord('A')
    else:
        return 1 + ord('Z') - ord(word)


left = -1
right = 1

searchable = ''

def search(name, position, direction, visit):
    move = 0

    if len(visit) == len(searchable):
        return 0

    while True:
        position = position + direction
        move += 1

        if position < 0:
            position = len(name) - 1
        elif position >= len(name):
            position = 0

        if name[position] != 'A':
            name = name[:position] + 'A' + name[position+1:]
            visit += name[position]
            break

    return move + min(search(name, position, left, visit), search(name, position, right, visit))


def solution(name):
    answer = 0

    global searchable
    searchable = ''

    for i,n in enumerate(name):
        if n != 'A':
            searchable += n

    for w in searchable:
        answer += get_letter_close(w)
    visit = ''

    if name[0] != 'A':
        name = 'A' + name[1:]
        visit += name[0]

    min_distance = min(search(name, 0, left, visit), search(name, 0, right, visit))

    answer += min_distance

    return answer


# print(solution("AAAAA"), 0)
# print(solution("JEROEN"), 56)
# print(solution("JAN"), 23)
# print(solution("ABAAAAAAAABB"), 7)
# print(solution("BBBBBBBBBBBBBBBBBBBB"), 23)
# print(solution("BBABAAAABBBAAAABABB"), 26)
# print(solution("BBAAAAAABBBAAAAAABB"), 20)
# print(solution("BBBAAAAAAAB"), 8)
