test=int(input())
for testidx in range(test):
    print(f"Case #{testidx+1}: ", end='')
    n, q = tuple([int(num) for num in input().split()])
    k=int(input())
    k = k/1000000
    dsu = [0 for i in range(n+1)]
    a = [0 for i in range(n+1)]
    b = [0 for i in range(n+1)]
    for i in range(2,n+1):
        p_, a_, b_ = tuple([int(num) for num in input().split()])
        dsu[i] = p_
        a[i] = a_/(1000000)
        b[i] = b_/(1000000)
    queries = []

    for _ in range(q):
        u, v = tuple([int(num) for num in input().split()])
        queries.append([u,v])
    

    p = [ -1 for i in range(n+1)]

    def solve(i):
        if i == 1:
            return k
        else:
            return b[i] + solve(dsu[i])*(a[i]-b[i])
            
    
    for i in range(1,n+1):
        p[i] = solve(i)
    
    #print("prob", p)

    def isParent(i,j):
        idx = j
        while idx > 0:
            if dsu[idx] == i:
                return True
            idx = dsu[idx]
        print(i,j,False)
        return False

    

    for que in queries:
        u, v = tuple(que)
        ans = p[u]*a[v] + (1-p[u])*b[v]
        
        #print("dec", ans)
        nr, dr = (ans).as_integer_ratio()
        nr = nr%(1000000000+7)
        r = nr
        print(r, end=' ')
    print()