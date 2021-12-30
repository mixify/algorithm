'''
만들 수 없는 금액 - 이것이 취업을 위한 코딩 테스트다 with 파이썬 314 P
답지보고 풀었음
'''


ary = [1,2,3,0,5,0,7,0,9]

sorted_ary = sorted([i for i in ary if i!=0]) + [i for i in ary if i==0]

print(sorted_ary)


# top1 = -1
# top2 = -1
# perv_top = -1
#
# for i in ary:
#     top1 = max(top1, i)
#     top2 = max(top2, i)
#     if top1 == top2:
#         top2 = perv_top
#     perv_top = top1
#
#
# print(top1 + top2)
#     # top2 = max()
#
#
#
#
