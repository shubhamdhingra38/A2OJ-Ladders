import sys
from collections import defaultdict

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
    a, b = map(int, input().split(' '))
    res = float('inf')
    res = min(res, max(2 * a, b))
    res = min(res, max(2 * b, a))
    print(res ** 2)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
