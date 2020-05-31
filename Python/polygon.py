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
    mat = [input().split('\n')[0] for i in range(n)]
    flag = True
    for i in range(n):
        if not flag:
            break
        for j in range(n):
            if mat[i][j] == '1':
                if i == n-1 or j == n-1 or mat[i+1][j] == '1' or mat[i][j+1] == '1':
                    continue
                else:
                    flag = False
                    break
    print("YES" if flag else "NO")

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
