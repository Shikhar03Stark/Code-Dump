def form(x):
    if x < 10:
        return f'0{x}'
    return x

start = [int(u) for u in input().split()]
travel = [int(u) for u in input().split()]

mm = start[1] + travel[1]
ex = mm // 60
mm = mm % 60

hh = (start[0] + travel[0] + ex) % 24

print(f'{form(hh)} {form(mm)}')