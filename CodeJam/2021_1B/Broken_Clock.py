n = int(input())

for tc in range(n):
    t1, t2, t3= [int(i) for i in input().split(' ')]
    tick = 1/12 * 10**(-10)
    t1 = t1*tick
    t2 = t2*tick
    t3 = t3*tick
    #print(f"Case *: {t1} {t2} {t3}")
    se = 0
    hr = 0
    mi = 0
    adj = 3
    while adj:
        if t1%6 == 0:
            se = int(t1//6)
            if t2/360 == (t3%30)/30:
                mi = int(t2//6)
                hr = int(t3//30)
            else:
                mi = int(t3//6)
                hr = int(t2//30)
            break

        t1, t2, t3 = t2, t3, t1
        adj = adj-1

    print(f"Case #{tc+1}: {hr} {mi} {se} {0}")