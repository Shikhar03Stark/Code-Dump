t = int(input())
while t>0:
    arr = input().split(' ')
    k1, k2, k3, v = [float(num) for num in arr]
    final = k1*k2*k3*v
    final = 100/final
    final = round(final, 2)
    if final < 9.58:
        print('YES')
    else:
        print('NO')
    t = t-1