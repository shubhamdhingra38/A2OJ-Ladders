import sys
from collections import defaultdict, Counter
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
    """
    """
    n, k = map(int, input().split())
    s = input()
    if k == 1:
        print(''.join(sorted(s[:-1])))
    else:
        s = s[:-1]
        l = sorted(s)
        freq = Counter(s)
        characters = sorted(list(set(s)))
        if len(freq.keys()) >= 3:
            if freq[characters[0]] < k:
                print(l[k-1])
            else:
                prefix = characters[0] * (freq[characters[0]]-k+1)
                suffix = ''.join([characters[i] * freq[characters[i]] for i in range(1, len(characters))])
                print(prefix + suffix)
        elif len(freq.keys()) == 2:
            if freq[characters[0]] < k:
                print(l[k-1])
            else:
                if freq[characters[0]] == k:
                    m1 = int(math.ceil(freq[characters[0]]/k))
                    m2 = int(math.ceil(freq[characters[1]]/k))
                    result = characters[0] * m1 + characters[1] * m2
                else:
                    m1 = characters[0] * (freq[characters[0]]-k+1)
                    m2 = characters[1] * freq[characters[1]]
                    result = m1 + m2
                print(result)
        else:
            m1 = int(math.ceil(freq[characters[0]]/k))
            print(characters[0] * m1)

            


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        solve()
