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
    return [x for x in s]

# @timer
def solve():
    h, c, t = map(int, input().split(' '))
    if 2 * t <= h + c:
        return '2'
    x = int((t - h)/(h + c - 2 * t))
    a, b = x, x + 1
    tt = t * (2 * a + 1) * ( 2 * b + 1)
    aa = abs(tt - (a * (c + h) + h) * (2 * b + 1))
    bb = abs(tt - (b * (c + h) + h) * (2 * a + 1))
    if aa <= bb:
        return str(2 * a + 1)
    return str(2 * b + 1)

if __name__ == '__main__':
    t = int(input())
    l = []
    for _ in range(t):
        l.append(solve())
    print('\n'.join(l))
