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


def prime_factorization(num, k):
    res = num
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            d1, d2 = num // i, i
            if d1 <= k:
                res = min(res, d2)
            if d2 <= k:
                res = min(res, d1)
    return res

# @timer
def solve():
    n, k = map(int, input().split(' '))
    if k >= n:
        res = 1
    else:
        res = prime_factorization(n, k)
    print(res)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
