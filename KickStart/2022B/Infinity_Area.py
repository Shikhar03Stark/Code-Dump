import math


tt = int(input())
for tc in range(1, tt+1):
    print(f'Case #{tc}: ', end='')
    (r, a, b) = (int(num) for num in input().split())
    ans = math.pi*r*r
    div = False
    while r>0:
        if div:
            r = r//b
            div = False
        else:
            r = r*a
            div = True

        ans += math.pi*r*r 

    print(ans, end='\n')
