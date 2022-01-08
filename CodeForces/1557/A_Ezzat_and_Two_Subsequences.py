t = int(input())
while t > 0:
    n = int(input())
    ll = []
    string = input()
    ll = [float(elem) for elem in string.split(' ')]
    sorted(ll, reverse=True)
    a = ll[0]
    b = 0
    for elem in ll[1:]:
        b += elem
    b /= n-1
    print(a+b)
    t -= 1