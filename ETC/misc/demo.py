from black import diff


def missingWords(s, t):
    sw = s.split(' ')
    tw = t.split(' ')
    ans = []
    i = 0
    j = 0
    while i<len(sw):
        if tw[j] == sw[i]:
            i += 1
            j += 1
        else:
            ans.append(sw[i])
            i += 1

    return ans

def helper(s):
    ans = 0
    n = len(s)
    cont = 1
    for i in range(1,n):
        if s[i] == s[i-1]:
            cont += 1
        else:
            ans += cont//2
            cont = 1
    
    ans += cont//2
    return ans

def minimalOperation(words):
    return [helper(word) for word in words]

def consecutiveCount(s, char):
    ans = 0
    n = len(s)
    cont = 0
    for i in range(n):
        if s[i] == char:
            cont += 1
        else:
            ans += max(0, cont-2)
            cont = 0
        
    ans += max(0, cont-2)
    return ans

def gameWinner(color):
    bc = consecutiveCount(color, 'b')
    wc = consecutiveCount(color, 'w')
    print(bc, wc)
    if wc > bc:
        return 'wendy'
    else:
        return 'bob'


def countMax(upRight):
    rect = [coord.split() for coord in upRight]
    row = [int(coord[0]) for coord in rect]
    col = [int(coord[1]) for coord in rect]
    minrow = min(row)
    mincol = min(col)

    return minrow*mincol


def minNum(samDaily, kellyDaily, difference):
    if kellyDaily > samDaily:
        days = 0
        qKelly = 0
        qSam = difference
        while True:
            if qKelly > qSam:
                return days
            qKelly += kellyDaily
            qSam += samDaily
            days += 1
    else:
        return -1

# print(missingWords("I like cheese", "cheese"))
# print(minimalOperation(['add', 'boook', 'break']))
# print(gameWinner('wwwbb'))
# print(countMax(['1 4', '2 3', '4 1']))
print(minNum(4, 5, 5))