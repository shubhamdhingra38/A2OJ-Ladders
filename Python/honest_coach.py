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
    arr = [int(x) for x in input().split(' ')]
    res = float('inf')
    for i in range(len(arr)):
        for j in range(i+1, len(arr)):
            res = min(res, abs(arr[i] - arr[j]))
    print(res)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
