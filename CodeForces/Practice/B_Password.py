s = input()
n = len(s)
p = [0]
for i in range(1,n):
    j = p[i-1]
    while (j>0 and s[i] != s[j]):
        j = p[j-1]
    if s[i]==s[j]:
        p.append(j+1)
    else:
        p.append(0)
#print(p)
if p[n-1] > 0:
    for i in range(n-1):
        if p[i] == p[n-1]:
            print(s[:p[n-1]])
            exit(0)
    if p[p[n-1]-1] > 0:
        print(s[:p[p[n-1]-1]])
        exit(0)
    print("Just a legend")
else:
    print("Just a legend")