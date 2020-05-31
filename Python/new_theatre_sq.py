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
    n, m, x, y = map(int, input().split(' '))
    mat = [string_to_arr(input().split('\n')[0]) for i in range(n)]
    cost = 0
    for i in range(n):
        for j in range(m):
            if mat[i][j] == '.':
                if j != m - 1 and mat[i][j+1] == '.':
                    cost += min(2 * x, y)
                    mat[i][j+1] = '*'
                else:
                    cost += x
                mat[i][j] = '*'
    print(cost)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
