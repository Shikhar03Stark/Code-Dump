t = int(input())
while t > 0:
    n = int(input())
    b = input().split(' ')
    b = [int(e) for e in b]
    b = sorted(b)
    sum = 0
    for i in range(n+1):
        sum = sum + b[i]

    done = False
    for i in range(n+1):
        if i == n:
            if sum - b[n] == b[n+1] or sum - b[n] == b[n]:
                for j in range(n+1):
                    if j != i:
                        print(b[j], end=' ')
                print()
                done = True
                break
        
        if sum - b[i] == b[n+1]:
            for j in range(n+1):
                if j != i:
                    print(b[j], end=' ')
            print()
            done = True
            break
    
    if not done:
        print("-1")

    t = t-1