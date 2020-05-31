import sys
from collections import defaultdict
import math

input = sys.stdin.readline


def print_result(l): return print(' '.join(map(str, l)))


def timer(function):
    import time

    def wrapper(*args, **kwargs):
        t1 = time.time()
        val = function()
        t2 = time.time()
        print("Executed \{}\ in {:.2f} seconds.".format(function.__name__, t2-t1))
        return val
    return wrapper


def string_to_arr(s):
    res = [x for x in s]
    return res

def is_valid(a, b):
    cnt = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            cnt += 1
    return cnt <= 1

# @timer
def solve():
    n, m = map(int, input().split(' '))
    arr = [string_to_arr(input().split('\n')[0]) for i in range(n)]
    possible = False
    # print(arr)
    oldchr, res = '', ''
    for i in range(m):
        s = arr[0].copy()
        oldchr = s[i]
        for c in range(26):
            flag = False
            s[i] = chr(ord('a') + c)
            for j in range(n):
                string = arr[j]
                if not is_valid(string, s):
                    flag = True
                    break
            if not flag:
                possible = True
                res = s
                break
        if not possible:
            s[i] = oldchr
        else:
            break
    if not possible:
        print(-1)
    else:
        print(''.join(res))



if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
