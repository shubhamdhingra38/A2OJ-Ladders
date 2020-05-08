n = int(input())
print(' ' * 2 * n + '0')
arr = []
for i in range(1, n+1):
    s = ' ' * (2*(n-i))
    for j in range(i):
        s += str(j) + ' '
    arr.append(s + str(i) + s[::-1])
    print(arr[-1].rstrip(' '))
for i in range(n-1)[::-1]:
    print(arr[i].rstrip(' '))
print(' ' * 2 * n + '0')
