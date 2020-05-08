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
    n = int(input())
    assert n%2 == 0
    min_sum = (2**n + sum([2**i for i in range(1, n//2)]) - sum([2**i for i in range(n//2, n)]))
    print(min_sum) 


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
