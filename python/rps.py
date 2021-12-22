def winner(shapes):
    if 'P' in shapes and 'S' in shapes:
        return 'S'
    if 'P' in shapes and 'R' in shapes:
        return 'P'
    if 'S' in shapes and 'R' in shapes:
        return 'R'

def loser(shapes):
    if 'P' in shapes and 'S' in shapes:
        return 'P'
    if 'P' in shapes and 'R' in shapes:
        return 'R'
    if 'S' in shapes and 'R' in shapes:
        return 'S'

def solution(n, m, points, hands):
    answer = 0

    scores = [0] * (n + 1)
    for i in range(m):
        hand_dic = {}

        hand_dic.setdefault('R', [0, []])
        hand_dic.setdefault('P', [0, []])
        hand_dic.setdefault('S', [0, []])

        shapes = set()
        for idx, h in enumerate(hands[i]):
            hand_dic[h][0] += 1
            hand_dic[h][1].append(idx + 1)
            shapes.add(h)

        if len(shapes) == 1:
            if i == m - 1:
                break
            points[i + 1] += points[i]
            continue
        elif len(shapes) == 2:
            if points[i] >= 0:
                for people_idx in hand_dic[winner(shapes)][1]:
                    scores[people_idx] += points[i]
            else:
                for people_idx in hand_dic[loser(shapes)][1]:
                    scores[people_idx] += points[i]
        else:
            if hand_dic['R'][0] == hand_dic['P'][0] and hand_dic['R'][0] == hand_dic['S'][0]:
                if i == m - 1:
                    break
                points[i + 1] += points[i]
                continue
            elif hand_dic['R'][0] == hand_dic['P'][0]:
                for people_idx in hand_dic['S'][1]:
                    scores[people_idx] += points[i]
            elif hand_dic['R'][0] == hand_dic['S'][0]:
                for people_idx in hand_dic['P'][1]:
                    scores[people_idx] += points[i]
            elif hand_dic['P'][0] == hand_dic['S'][0]:
                for people_idx in hand_dic['R'][1]:
                    scores[people_idx] += points[i]
            else:
                sorted_by_count = [k for k, v in sorted(hand_dic.items(), key=lambda x: x[1][0])]
                # print(hand_dic)
                # print(sorted_by_count)
                if points[i] >= 0:
                    sorted_by_count.pop(2)  # 가장 큰 그룹 제거
                    for people_idx in hand_dic[winner(sorted_by_count)][1]:
                        scores[people_idx] += points[i]
                else:
                    sorted_by_count.pop(0)  # 가장 적은 그룹 제거
                    for people_idx in hand_dic[loser(sorted_by_count)][1]:
                        scores[people_idx] += points[i]


                # for k,v in hand_dic.items():
                #     print(k,v)


    answer = max(scores[1:])
    return answer


# print(solution(6,5,[5, -2, 1, 3, -5],["PSPRSS", "SSRRSS", "RRRRRR", "RRSSPP", "SSSRRP"]), 4)
print(solution(6,2,[5, -2],["RRRPPP", "RRRPPP"]), 0)
