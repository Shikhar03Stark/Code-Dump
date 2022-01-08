t = int(input())
while t>0 :
    n = int(input())
    tot = n*(n+1) // 2
    count = 0
    for m in range(1,n):
        diff = abs(tot - 2*m)
        if(diff % 2 == 0):
            rng = diff//2
            if rng == 0:
                count += 1
            else:
                for i in range(m, m-rng, -1):
                    if(i == 0):
                        break
                    if(i+rng <= n and i+rng > m):
                        count += 1
    print(count)
    t -=1