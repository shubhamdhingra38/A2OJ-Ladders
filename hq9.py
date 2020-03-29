s = input()
flg = False
for ch in s:
    if ch in ['H', 'Q', '9']:
        flg = True
        break
if flg: print("YES")
else: print("NO")