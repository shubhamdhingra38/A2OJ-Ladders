n = int(input())
arr = [int(x) for x in input().split(' ')]
cnt_5 = arr.count(5)
cnt_0 = arr.count(0)
while cnt_5 != 0:
    if (5*cnt_5) % 9 == 0:
        break
    cnt_5 -= 1
if cnt_5 == 0:
    if cnt_0 == 0:
        print('-1')
    else:
        print('0')
else:
    if cnt_0 != 0:
        print('5' * cnt_5 + '0' * cnt_0)
    else:
        print(-1)