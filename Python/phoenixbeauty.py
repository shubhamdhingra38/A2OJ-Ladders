import sys
from collections import defaultdict

input = sys.stdin.readline


def print_result(l): return print(' '.join(map(str, l)))

def is_beautiful(arr, k):
    flag = True
    s = sum(arr[:k])
    for i in range(len(arr)-k+1):
        temp = 0
        for j in range(k):
            temp += arr[i+j]
        if temp != s:
            flag = False
            break
    return flag

def timer(function):
    import time

    def wrapper(*args, **kwargs):
        t1 = time.time()
        val = function()
        t2 = time.time()
        print("Executed \{}\ in {:.2f} seconds.".format(function.__name__, t2-t1))
        return val
    return wrapper


MAX = int(1e4)
# @timer

MAX = int(1e4)
def solve():
    n, k = map(int, input().split(' '))
    arr = [int(x) for x in input().split(' ')]
    d = defaultdict(int)
    for ele in arr:
        d[ele] += 1
    if len(d.keys()) > k:
        print(-1)
    else:
        l = list(d.keys())
        length_of_list = len(l)
        l *= k//length_of_list
        if k % length_of_list != 0:
            l += l[:k % length_of_list]
        res = l * (MAX//len(l))
        print(len(res))
        print(*res)
        # print(is_beautiful(res, k))
            
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
