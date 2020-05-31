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



# @timer
def solve():
    n, m, k = map(int, input().split(' '))
    cards_each = n // k
    if cards_each >= m:
        res = m
    else:
        m -= cards_each
        others = math.ceil(m / (k-1))
        res = cards_each - others
    print(res)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
