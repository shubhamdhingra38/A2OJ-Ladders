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
    d = defaultdict(int)
    n_even, n_odd = 0, 0
    flag = False
    for ele in arr:
        d[ele] += 1
        if ele % 2 == 0:
            n_even += 1
        else:
            n_odd += 1
    if n_even % 2 == 0 and n_odd % 2 == 0:
        flag = True
    else:
        if n_even % 2 != 0 and n_odd % 2 != 0:
            for ele in arr:
                if d[ele-1] != 0 or d[ele+1] != 0:
                    flag = True
                    break
    print("YES" if flag else "NO")


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
