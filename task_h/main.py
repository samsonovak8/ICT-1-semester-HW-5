from math import sqrt

n = int(input())
ans = -1
for i in range(n):
    x = n - i**2
    if x >= 0 and int(sqrt(x)) * int(sqrt(x)) == x:
        if i == 0:
            ans=1
        else:
            ans=2
        break
if ans == -1:
    while n > 0 and n % 4 == 0:
        n /= 4
    if n - 7 > 0 and (n - 7) % 8 == 0:
        ans = 4
    else:
        ans = 3
print(ans)