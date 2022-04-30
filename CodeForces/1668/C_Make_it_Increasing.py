n = int(input())
a = [int(x) for x in input().split(' ')]
# print(a)
ans = -1
for p in range(n):
    b = [0]*n
    # print(b)
    cnt = 0
    # print('p', p)
    for i in range(p+1, n):
        n = b[i-1]//a[i] + 1
        cnt += n
        b[i] = n*a[i]
    # print(list(reversed(range(p))))
    i = p-1
    print(b)
    while i>=0:
        # print(b[i+1])
        n = b[i+1]//a[i] + 1
        cnt += n
        b[i] = n*a[i]
        i -= 1

    if ans == -1 or cnt < ans:
        ans = cnt

print(ans, end='\n')